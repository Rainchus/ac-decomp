#include "jsyswrap_cpp.h"

#include "JSystem/JSystem.h"
#include "JSystem/JUtility/JUTGamePad.h"
#include "JSystem/JUtility/TColor.h"
#include "libforest/emu64.h"
#include "_mem.h"
#include "m_lib.h"
#include "dolphin/os/OSArena.h"
#include "libc64/malloc.h"

/* These bytes are probably generated by an unused function that got stripped... thanks mwcc */
#ifdef MUST_MATCH
#pragma force_active on
u8 _jsyswrap_autogen_match[0x40];
#pragma force_active reset
#endif

JUTGamePad gamePad[4];
static void* jc_fader = nullptr;
static void* forest_arc_aram_p = nullptr;
static void* forest_arc_aram2_p = nullptr;
static void* gameheap_base;
static void* jc_gport = nullptr;
static void* jc_sysConsole = nullptr;
static u8 video_progressive = 0;
static u8 video_lowreso = 0;
static u8 video_famicom = 0;
static u8 video_logo = 0;
static u8 video_pan_enable = 0;
static u16 video_pan_xorg = 0;
static u16 video_pan_yorg = 0;
static u16 video_pan_width = 0;
static u16 video_pan_height = 0;

static u32 SystemHeapSize = 0x16C7000;
static u32 gameheap_len = 0x380000;
static GXRenderModeObj customized_GXNtsc240Ds = {
  VI_TVMODE_NTSC_DS,
  640,
  240,
  240,
  30,
  0,
  660,
  480,
  VI_XFBMODE_SF,
  FALSE,
  FALSE,
  {
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 }
  },
  { 0, 0, 21, 22, 21, 0, 0 }
};
static GXRenderModeObj customized_GXNtsc240Prog = {
  VI_TVMODE_NTSC_PROG,
  640,
  240,
  480,
  30,
  0,
  660,
  480,
  VI_XFBMODE_SF,
  FALSE,
  FALSE,
  {
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 }
  },
  { 0, 0, 21, 22, 21, 0, 0 }
};
static GXRenderModeObj customized_GXNtsc240IntDf = {
  VI_TVMODE_NTSC_INT,
  640,
  240,
  480,
  30,
  0,
  660,
  480,
  VI_XFBMODE_DF,
  FALSE,
  FALSE,
  {
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 }
  },
 { 8, 8, 10, 12, 10, 8, 8 }
};
static GXRenderModeObj customized_GXNtsc480Ds = {
  VI_TVMODE_NTSC_DS,
  640,
  480,
  240,
  30,
  0,
  660,
  480,
  VI_XFBMODE_SF,
  FALSE,
  FALSE,
  {
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 }
  },
  { 0, 0, 21, 22, 21, 0, 0 }
};
static GXRenderModeObj customized_GXNtsc480IntDf = {
  VI_TVMODE_NTSC_INT,
  640,
  480,
  480,
  30,
  0,
  660,
  480,
  VI_XFBMODE_DF,
  FALSE,
  FALSE,
  {
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 }
  },
  { 8, 8, 10, 12, 10, 8, 8 }
};
static GXRenderModeObj customized_GXNtsc480Prog = {
  VI_TVMODE_NTSC_PROG,
  640,
  480,
  480,
  30,
  0,
  660,
  480,
  VI_XFBMODE_SF,
  FALSE,
  FALSE,
  {
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 },
    { 6, 6 }
  },
  { 0, 0, 21, 22, 21, 0, 0 }
};

static void ReportDiskID() {
  DVDDiskID* disk_id = DVDGetCurrentDiskID();

  /* @NOTE: taken from e+ */
  JSYSWRAPPER_PRINTF(jc_sysConsole, "DiskID %.4s %.2s %d 0x%02x(%d)\n", disk_id->gameName, disk_id->company, disk_id->diskNumber, disk_id->gameVersion);
}

extern void JW_UpdateVideoMode() {
  GXRenderModeObj* renderMode;

  if (video_famicom) {
    video_pan_xorg = 32;
    video_pan_yorg = 8;
    video_pan_width = 256;
    video_pan_height = 232;

    if (video_lowreso != FALSE && video_progressive == FALSE) {
      renderMode = &customized_GXNtsc240Ds;
    }
    else {
      video_pan_yorg *= 2;
      video_pan_height *= 2;

      if (video_progressive != FALSE) {
        renderMode = &customized_GXNtsc240Prog;
      }
      else {
        renderMode = &customized_GXNtsc240IntDf;
      }
    }
  }
  else {
    if (video_logo) {
      video_pan_xorg = 0;
      video_pan_yorg = 0;
      video_pan_width = 640;
      video_pan_height = 480;
    }
    else {
      video_pan_xorg = 20;
      video_pan_yorg = 6;
      video_pan_width = 598;
      video_pan_height = 464;
    }

    if (video_progressive) {
      renderMode = &customized_GXNtsc480Prog;
    }
    else {
      renderMode = &customized_GXNtsc480IntDf;
    }
  }

  if (renderMode != NULL) {
    VIWaitForRetrace();
    JC_JUTVideo_setRenderMode(JC_JUTVideo_getManager(), renderMode);
  }

  if (video_pan_enable) {
    VIConfigurePan(video_pan_xorg, video_pan_yorg, video_pan_width, video_pan_height);
  }
}

extern void JW_SetProgressiveMode(int enabled) {
  if (video_progressive != enabled) {
    video_progressive = enabled;
    JW_UpdateVideoMode();
  }
}

extern void JW_SetLowResoMode(int enabled) {
  if (video_lowreso != enabled) {
    video_lowreso = enabled;
    JW_UpdateVideoMode();
  }
}

extern void JW_SetFamicomMode(int enabled) {
  if (video_famicom != enabled) {
    video_famicom = enabled;
    JW_UpdateVideoMode();
  }
}

extern void JW_SetVideoPan(u16 origin_x, u16 origin_y, u16 width, u16 height) {
  if (video_pan_xorg != origin_x || video_pan_yorg != origin_y || video_pan_width != width || video_pan_height != height) {
    video_pan_enable = TRUE;
    video_pan_xorg = origin_x;
    video_pan_yorg = origin_y;
    video_pan_width = width;
    video_pan_height = height;
  }
}

extern void JW_SetLogoMode(int enabled) {
  if (video_logo != enabled) {
    video_logo = enabled;
    JW_UpdateVideoMode();
  }
}

extern void JW_JUTGamePad_read() {
  static OSTime last_pad_read;
  OSTime now = OSGetTime();

  if (now > last_pad_read + OSMillisecondsToTicks(16) || now  < last_pad_read) {
    last_pad_read = now;
    JC_JUTGamePad_read();
  }
}

extern void JW_getPadStatus(PADStatus* padStatus) {
  memcpy(&padStatus[0], &JUTGamePad::mPadStatus[0], sizeof(PADStatus));
  memcpy(&padStatus[1], &JUTGamePad::mPadStatus[1], sizeof(PADStatus));
  memcpy(&padStatus[2], &JUTGamePad::mPadStatus[2], sizeof(PADStatus));
  memcpy(&padStatus[3], &JUTGamePad::mPadStatus[3], sizeof(PADStatus));
}

extern int JW_JUTGamepad_getErrorStatus() {
  return (s8)((JUTGamePad*)gamePad)[0].mErrorStatus;
}

extern u32 JW_JUTGamepad_getButton() {
  return ((JUTGamePad*)gamePad)[0].mButtons.mButton;
}

extern u32 JW_JUTGamepad_getTrigger() {
  return ((JUTGamePad*)gamePad)[0].mButtons.mTrigger;
}

extern f32 JW_JUTGamepad_getSubStickValue() {
  return ((JUTGamePad*)gamePad)[0].mSubStick.mValue;
}

extern int JW_JUTGamepad_getSubStickAngle() {
  return ((JUTGamePad*)gamePad)[0].mSubStick.mAngle;
}

static bool FrameDrawing = false;

extern void JW_BeginFrame() {
  while (FrameCansel) {
    VIWaitForRetrace();
  }

  FrameDrawing = true;
  void* displayManager = JC_JFWDisplay_getManager();
  JC_JFWDisplay_endFrame(displayManager);
  JC_JFWDisplay_beginRender(displayManager);
  JC_J2DOrthoGraph_setOrtho(jc_gport, 0, 0, JC_JFWDisplay_getEfbWidth(displayManager), JC_JFWDisplay_getEfbHeight(displayManager));
  JC_J2DOrthoGraph_setPort(jc_gport);
}

extern void JW_EndFrame() {
  JC_JFWDisplay_endRender(JC_JFWDisplay_getManager());
  FrameDrawing = false;
}

extern int JW_setClearColor(u8 r, u8 g, u8 b) {
  static GXColor clear_color;

  if (clear_color.r != r || clear_color.g != g || clear_color.b != b) {
    void* manager = JC_JFWDisplay_getManager();

    clear_color.r = r;
    clear_color.g = g;
    clear_color.b = b;

    JC_JFWDisplay_setClearColor(manager, clear_color);
    return TRUE;
  }
  
  return FALSE;
}

static const char* aram_resName[] = {
  "fgdata.bin",
  "mail_data.bin",
  "mail_data_table.bin",
  "maila_data.bin",
  "maila_data_table.bin",
  "mailb_data.bin",
  "mailb_data_table.bin",
  "mailc_data.bin",
  "mailc_data_table.bin",
  "pallet_boy.bin",
  "ps_data.bin",
  "ps_data_table.bin",
  "psz_data.bin",
  "psz_data_table.bin",
  "select_data.bin",
  "select_data_table.bin",
  "string_data.bin",
  "string_data_table.bin",
  "superz_data.bin",
  "superz_data_table.bin",
  "super_data.bin",
  "super_data_table.bin",
  "tex_boy.bin",
  "face_boy.bin",
  "fgnpcdata.bin",
  "message_data.bin",
  "message_data_table.bin",
  "my_original.bin",
  "needlework.bin",
  "player_room_floor.bin",
  "player_room_wall.bin",
  "npc_name_str_table.bin",
  "d_obj_npc_stock_sch.bin",
  "d_obj_npc_stock_scl.bin",
  "title.bti",
  "mura_spring.bti",
  "mura_summer.bti",
  "mura_fall.bti",
  "mura_winter.bti",
  "odekake.bti",
  "omake.bti",
  "eki1.bti",
  "eki1_2.bti",
  "eki1_3.bti",
  "eki1_4.bti",
  "eki1_5.bti",
  "eki2.bti",
  "eki2_2.bti",
  "eki2_3.bti",
  "eki2_4.bti",
  "eki2_5.bti",
  "eki3.bti",
  "eki3_2.bti",
  "eki3_3.bti",
  "eki3_4.bti",
  "eki3_5.bti",
  "tegami.bti",
  "tegami2.bti",
  "famikon.bti",
  "boy1.bti",
  "boy2.bti",
  "boy3.bti",
  "boy4.bti",
  "boy5.bti",
  "boy6.bti",
  "boy7.bti",
  "boy8.bti",
  "girl1.bti",
  "girl2.bti",
  "girl3.bti",
  "girl4.bti",
  "girl5.bti",
  "girl6.bti",
  "girl7.bti",
  "girl8.bti",
  "d_bg_island_sch.bin"
};

extern u32 JW_GetAramAddress(int res_no) {
  int address = 0;

  if (res_no >= RESOURCE_FGDATA && res_no < RESOURCE_FGNPCDATA) {
    address = JC_JKRAramArchive_getAramAddress_byName(forest_arc_aram_p, (u32)'DATA', aram_resName[res_no]);
  }
  else if (res_no >= RESOURCE_FGNPCDATA && res_no < RESOURCE_NUM) {
    address = JC_JKRAramArchive_getAramAddress_byName(forest_arc_aram2_p, (u32)'DATA', aram_resName[res_no]);
  }

  return address;
}

extern u8* _JW_GetResourceAram(u32 aram_addr, u8* dst, u32 size) {
  return JKRAramToMainRam(aram_addr, dst, size, EXPAND_SWITCH_DEFAULT, 0, nullptr, -1, nullptr);
}

extern u32 JW_GetResSizeFileNo(int res_no) {
  int res_size = 0;

  if (res_no >= RESOURCE_FGDATA && res_no < RESOURCE_FGNPCDATA) {
    CSDIFileEntry* entry = JC__JKRGetResourceEntry_byName((u32)'DATA', aram_resName[res_no], forest_arc_aram_p);

    if (entry != nullptr) {
      res_size = entry->mSize;
    }
  }
  else if (res_no >= RESOURCE_FGNPCDATA && res_no < RESOURCE_NUM) {
    CSDIFileEntry* entry = JC__JKRGetResourceEntry_byName((u32)'DATA', aram_resName[res_no], forest_arc_aram2_p);

    if (entry != nullptr) {
      res_size = entry->mSize;
    }
  }

  return res_size;
}

extern void JW_Init() {
  const u32 soundAramSize = 0x810000;
  const u32 graphAramSize = 0x6A3780;

  void* arena_hi = OSGetArenaHi();
  void* arena_lo = OSGetArenaLo();

  SystemHeapSize = (u32)arena_hi - (u32)arena_lo - 0xD0;
  JC_JFWSystem_setMaxStdHeap(1);
  JC_JFWSystem_setSysHeapSize(SystemHeapSize);
  JC_JFWSystem_setFifoBufSize(0x10001);
  OSReport("soundAramSize=%08x graphAramSize=%08x totalAramSize=%08x\n", soundAramSize, graphAramSize, soundAramSize + graphAramSize);
  JC_JFWSystem_setAramAudioBufSize(soundAramSize);
  JC_JFWSystem_setAramGraphBufSize(graphAramSize);
  JC_JFWSystem_init();
  JC_JKRExpHeap_changeGroupID(JC_JFWSystem_getSystemHeap(), 1);
  jc_sysConsole = JC_JFWSystem_getSystemConsole();
  JC_JUTConsole_setOutput(jc_sysConsole, 3);
  JC_JUTConsole_setPosition(jc_sysConsole, 32, 42);
  void* display_manager = JC_JFWDisplay_createManager_0(&GXNtsc480IntDf, JC_JFWSystem_getSystemHeap(), 2, 1);
  JC_JUTProcBar_setVisible(JC_JUTProcBar_getManager(), FALSE);
  JC_JUTProcBar_setVisibleHeapBar(JC_JUTProcBar_getManager(), FALSE);
  jc_gport = JC_J2DOrthoGraph_new();
  u32 color = TCOLOR_BLACK;
  jc_fader = JC_JUTFader_new(0, 0, JC_JUTVideo_getFbWidth(JC_JUTVideo_getManager()), JC_JUTVideo_getEfbHeight(JC_JUTVideo_getManager()), &color);
  JC_JFWDisplay_setFader(display_manager, jc_fader);
  JC_JFWDisplay_setClearColor(display_manager, TCOLOR_BLACK);
  JC_JFWDisplay_setGamma(display_manager, 0);
  JW_SetVideoPan(20, 6, 598, 464);
  JW_SetLogoMode(1);
  JC_JKRExpHeap_changeGroupID(JC_JFWSystem_getSystemHeap(), 2);
}

extern void JW_Init2() {
  JC_JKRExpHeap_changeGroupID(JC_JFWSystem_getSystemHeap(), 3);
  ReportDiskID();

  if (forest_arc_aram_p == nullptr) {
    forest_arc_aram_p = JC_JKRAramArchive_new();

    if (forest_arc_aram_p == nullptr || JC__JKRMountFixedAramArchive(forest_arc_aram_p, "forest_1st.arc") == FALSE) {
      OSDVDFatalError();
    }
  }

  gameheap_len = JC_JKRHeap_getFreeSize(JC_JFWSystem_getSystemHeap()) - 0x10000;
  gameheap_base = JC_JKRHeap_alloc(JC_JFWSystem_getSystemHeap(), gameheap_len, 32);
  MallocInit(gameheap_base, gameheap_len);
  JC_JKRExpHeap_changeGroupID(JC_JFWSystem_getSystemHeap(), 4);
}

extern void JW_Init3() {
  if (forest_arc_aram2_p == nullptr) {
    forest_arc_aram2_p = JC_JKRAramArchive_new();

    if (forest_arc_aram2_p == nullptr || JC__JKRMountFixedAramArchive(forest_arc_aram2_p, "forest_2nd.arc") == FALSE) {
      OSDVDFatalError();
    }
  }
}

extern void JW_Cleanup() {
  MallocCleanup();
  JC_JKRHeap_free(JC_JFWSystem_getSystemHeap(), gameheap_base);
  gameheap_base = nullptr;

  if (forest_arc_aram_p != nullptr) {
    JC__JKRUnmountFixedAramArchive(forest_arc_aram_p);
    JC_JKRAramArchive_delete(forest_arc_aram_p);
    forest_arc_aram_p = nullptr;
  }

  if (forest_arc_aram2_p != nullptr) {
    JC__JKRUnmountFixedAramArchive(forest_arc_aram2_p);
    JC_JKRAramArchive_delete(forest_arc_aram2_p);
    forest_arc_aram2_p = nullptr;
  }

  JC_JFWDisplay_destroyManager();

  if (jc_fader != nullptr) {
    JC_JUTFader_delete(jc_fader);
    jc_fader = nullptr;
  }

  if (jc_gport != nullptr) {
    JC_J2DOrthoGraph_delete(jc_gport);
    jc_gport = nullptr;
  }
}