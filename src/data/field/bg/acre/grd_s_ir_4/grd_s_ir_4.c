#include "libforest/gbi_extensions.h"

extern u8 wave3_tex_dummy[];
extern u8 wave2_tex_dummy[];
extern u8 wave1_tex_dummy[];
extern u8 sand_tex_dummy[];
extern u8 beach_pal_dummy2[];
extern u8 beach2_tex_dummy2[];
extern u8 beach1_tex_dummy2[];
extern u8 cliff_pal_dummy[];
extern u8 earth_pal_dummy[];
extern u8 bridge_2_pal_dummy[];
extern u8 bridge_2_tex_dummy[];
extern u8 river_tex_dummy[];
extern u8 grass_tex_dummy[];
extern u8 earth_tex_dummy[];

static Vtx grd_s_ir_4_v[] = {
#include "assets/field/bg/grd_s_ir_4_v.inc"
};

extern Gfx grd_s_ir_4_model[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, 0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 32, 48, 144, 255),
    gsSPDisplayList(0x0C000000),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(beach2_tex_dummy2, G_IM_FMT_I, 32, 16, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_ir_4_v[160], 32, 0),
    gsSPNTrianglesInit_5b(
        30, // tri count
        0, 1, 2, // tri0
        3, 4, 1, // tri1
        3, 5, 4 // tri2
    ),
    gsSPNTriangles_5b(
        4, 2, 1, // tri0
        3, 6, 5, // tri1
        6, 7, 5, // tri2
        6, 8, 7 // tri3
    ),
    gsSPNTriangles_5b(
        8, 9, 7, // tri0
        8, 10, 9, // tri1
        9, 11, 7, // tri2
        10, 12, 9 // tri3
    ),
    gsSPNTriangles_5b(
        10, 13, 12, // tri0
        13, 14, 12, // tri1
        13, 15, 14, // tri2
        15, 16, 14 // tri3
    ),
    gsSPNTriangles_5b(
        15, 17, 16, // tri0
        15, 18, 17, // tri1
        17, 19, 16, // tri2
        17, 20, 19 // tri3
    ),
    gsSPNTriangles_5b(
        17, 21, 20, // tri0
        15, 22, 18, // tri1
        18, 23, 17, // tri2
        23, 24, 17 // tri3
    ),
    gsSPNTriangles_5b(
        24, 21, 17, // tri0
        23, 25, 24, // tri1
        23, 26, 25, // tri2
        26, 27, 25 // tri3
    ),
    gsSPNTriangles_5b(
        26, 28, 27, // tri0
        28, 29, 27, // tri1
        28, 30, 29, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_ir_4_v[191], 4, 0),
    gsSPNTrianglesInit_5b(
        2, // tri count
        0, 1, 2, // tri0
        3, 0, 2, // tri1
        0, 0, 0 // tri2
    ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_TEX_EDGE2),
    gsDPSetCombineLERP(TEXEL0, 0, SHADE, 0, 0, 0, 0, TEXEL0, PRIMITIVE, 0, COMBINED, 0, 0, 0, 0, COMBINED),
    gsDPLoadTLUT_Dolphin(15, 16, 1, bridge_2_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(bridge_2_tex_dummy, G_IM_FMT_CI, 128, 32, 15, GX_CLAMP, GX_REPEAT, 0, 0),
    gsDPSetPrimColor(0, 128, 255, 255, 255, 255),
    gsSPLoadGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_FOG | G_LIGHTING | G_SHADING_SMOOTH),
    gsSPVertex(&grd_s_ir_4_v[229], 32, 0),
    gsSPNTrianglesInit_5b(
        22, // tri count
        0, 1, 2, // tri0
        0, 2, 3, // tri1
        1, 4, 5 // tri2
    ),
    gsSPNTriangles_5b(
        1, 5, 2, // tri0
        6, 7, 8, // tri1
        6, 8, 9, // tri2
        10, 11, 7 // tri3
    ),
    gsSPNTriangles_5b(
        10, 7, 6, // tri0
        11, 12, 13, // tri1
        11, 13, 7, // tri2
        14, 15, 16 // tri3
    ),
    gsSPNTriangles_5b(
        14, 16, 17, // tri0
        18, 14, 17, // tri1
        18, 17, 19, // tri2
        19, 17, 20 // tri3
    ),
    gsSPNTriangles_5b(
        19, 20, 21, // tri0
        22, 23, 24, // tri1
        22, 24, 25, // tri2
        26, 27, 23 // tri3
    ),
    gsSPNTriangles_5b(
        26, 23, 22, // tri0
        27, 28, 29, // tri1
        27, 29, 23, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_ir_4_v[259], 24, 0),
    gsSPNTrianglesInit_5b(
        18, // tri count
        0, 1, 2, // tri0
        0, 2, 3, // tri1
        4, 0, 3 // tri2
    ),
    gsSPNTriangles_5b(
        4, 3, 5, // tri0
        5, 3, 6, // tri1
        5, 6, 7, // tri2
        8, 9, 10 // tri3
    ),
    gsSPNTriangles_5b(
        8, 10, 11, // tri0
        12, 11, 13, // tri1
        12, 13, 14, // tri2
        15, 8, 11 // tri3
    ),
    gsSPNTriangles_5b(
        15, 11, 12, // tri0
        16, 17, 18, // tri1
        16, 18, 19, // tri2
        20, 21, 22 // tri3
    ),
    gsSPNTriangles_5b(
        20, 22, 17, // tri0
        23, 20, 17, // tri1
        23, 17, 16, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTLUT_Dolphin(15, 16, 1, cliff_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(river_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_ir_4_v[0], 32, 0),
    gsSPNTrianglesInit_5b(
        30, // tri count
        0, 1, 2, // tri0
        0, 2, 3, // tri1
        4, 0, 3 // tri2
    ),
    gsSPNTriangles_5b(
        4, 3, 5, // tri0
        6, 4, 5, // tri1
        6, 5, 7, // tri2
        8, 6, 7 // tri3
    ),
    gsSPNTriangles_5b(
        8, 7, 9, // tri0
        10, 8, 9, // tri1
        10, 9, 11, // tri2
        12, 10, 11 // tri3
    ),
    gsSPNTriangles_5b(
        12, 11, 13, // tri0
        14, 12, 13, // tri1
        15, 14, 13, // tri2
        16, 15, 13 // tri3
    ),
    gsSPNTriangles_5b(
        16, 13, 17, // tri0
        18, 16, 17, // tri1
        18, 17, 19, // tri2
        20, 18, 19 // tri3
    ),
    gsSPNTriangles_5b(
        20, 19, 21, // tri0
        22, 20, 21, // tri1
        23, 22, 21, // tri2
        23, 21, 24 // tri3
    ),
    gsSPNTriangles_5b(
        25, 23, 24, // tri0
        26, 25, 24, // tri1
        26, 24, 27, // tri2
        28, 26, 27 // tri3
    ),
    gsSPNTriangles_5b(
        29, 28, 27, // tri0
        30, 29, 27, // tri1
        30, 27, 31, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_ir_4_v[32], 22, 0),
    gsSPNTrianglesInit_5b(
        20, // tri count
        0, 1, 2, // tri0
        3, 0, 2, // tri1
        3, 2, 4 // tri2
    ),
    gsSPNTriangles_5b(
        5, 3, 4, // tri0
        6, 5, 4, // tri1
        7, 6, 4, // tri2
        7, 4, 8 // tri3
    ),
    gsSPNTriangles_5b(
        9, 7, 8, // tri0
        10, 9, 8, // tri1
        10, 8, 11, // tri2
        12, 10, 11 // tri3
    ),
    gsSPNTriangles_5b(
        13, 12, 11, // tri0
        13, 11, 14, // tri1
        15, 13, 14, // tri2
        15, 14, 16 // tri3
    ),
    gsSPNTriangles_5b(
        17, 15, 16, // tri0
        17, 16, 18, // tri1
        19, 17, 18, // tri2
        20, 19, 18 // tri3
    ),
    gsSPNTriangles_5b(
        21, 20, 18, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, beach_pal_dummy2),
    gsDPLoadTextureBlock_4b_Dolphin(sand_tex_dummy, G_IM_FMT_CI, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_ir_4_v[54], 5, 0),
    gsSPNTrianglesInit_5b(
        3, // tri count
        0, 1, 2, // tri0
        3, 0, 2, // tri1
        3, 2, 4 // tri2
    ),
    gsDPLoadTLUT_Dolphin(15, 16, 1, earth_pal_dummy),
    gsDPLoadTextureBlock_4b_Dolphin(earth_tex_dummy, G_IM_FMT_CI, 64, 64, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_ir_4_v[59], 32, 0),
    gsSPNTrianglesInit_5b(
        14, // tri count
        0, 1, 2, // tri0
        3, 0, 4, // tri1
        5, 6, 7 // tri2
    ),
    gsSPNTriangles_5b(
        8, 5, 9, // tri0
        1, 10, 11, // tri1
        10, 8, 12, // tri2
        13, 14, 15 // tri3
    ),
    gsSPNTriangles_5b(
        13, 16, 14, // tri0
        16, 17, 14, // tri1
        18, 19, 20, // tri2
        21, 22, 23 // tri3
    ),
    gsSPNTriangles_5b(
        15, 21, 24, // tri0
        25, 26, 27, // tri1
        28, 29, 30, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_ir_4_v[90], 12, 0),
    gsSPNTrianglesInit_5b(
        6, // tri count
        0, 1, 2, // tri0
        3, 4, 5, // tri1
        3, 5, 1 // tri2
    ),
    gsSPNTriangles_5b(
        6, 0, 2, // tri0
        7, 8, 9, // tri1
        10, 7, 11, // tri2
        0, 0, 0 // tri3
    ),
    gsDPLoadTextureBlock_4b_Dolphin(grass_tex_dummy, G_IM_FMT_CI, 32, 32, 15, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPVertex(&grd_s_ir_4_v[102], 32, 0),
    gsSPNTrianglesInit_5b(
        28, // tri count
        0, 1, 2, // tri0
        1, 3, 2, // tri1
        4, 5, 6 // tri2
    ),
    gsSPNTriangles_5b(
        5, 7, 6, // tri0
        4, 8, 5, // tri1
        7, 9, 6, // tri2
        7, 10, 9 // tri3
    ),
    gsSPNTriangles_5b(
        7, 11, 10, // tri0
        7, 12, 11, // tri1
        7, 2, 12, // tri2
        2, 13, 12 // tri3
    ),
    gsSPNTriangles_5b(
        2, 14, 13, // tri0
        2, 15, 14, // tri1
        2, 3, 15, // tri2
        8, 16, 17 // tri3
    ),
    gsSPNTriangles_5b(
        8, 18, 16, // tri0
        8, 17, 5, // tri1
        16, 19, 17, // tri2
        20, 21, 22 // tri3
    ),
    gsSPNTriangles_5b(
        21, 23, 22, // tri0
        23, 24, 22, // tri1
        24, 25, 22, // tri2
        25, 26, 22 // tri3
    ),
    gsSPNTriangles_5b(
        24, 27, 25, // tri0
        24, 28, 27, // tri1
        24, 29, 28, // tri2
        27, 30, 25 // tri3
    ),
    gsSPNTriangles_5b(
        30, 31, 25, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsSPVertex(&grd_s_ir_4_v[134], 22, 0),
    gsSPNTrianglesInit_5b(
        16, // tri count
        0, 1, 2, // tri0
        0, 3, 1, // tri1
        3, 4, 1 // tri2
    ),
    gsSPNTriangles_5b(
        4, 5, 1, // tri0
        4, 6, 5, // tri1
        7, 8, 9, // tri2
        7, 10, 8 // tri3
    ),
    gsSPNTriangles_5b(
        10, 11, 8, // tri0
        11, 12, 8, // tri1
        12, 13, 8, // tri2
        13, 14, 8 // tri3
    ),
    gsSPNTriangles_5b(
        14, 15, 8, // tri0
        15, 16, 8, // tri1
        16, 9, 8, // tri2
        17, 18, 19 // tri3
    ),
    gsSPNTriangles_5b(
        17, 20, 21, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetCombineLERP(PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, 0, 0, 0, TEXEL0, COMBINED, 0, SHADE, 0, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 206, 189, 148, 255),
    gsSPDisplayList(0x0C000000),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_OPA_SURF2),
    gsDPLoadTextureBlock_4b_Dolphin(beach1_tex_dummy2, G_IM_FMT_I, 64, 32, 15, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPVertex(&grd_s_ir_4_v[156], 4, 0),
    gsSPNTrianglesInit_5b(
        2, // tri count
        0, 1, 2, // tri0
        0, 2, 3, // tri1
        0, 0, 0 // tri2
    ),
    gsSPEndDisplayList(),
};

extern Gfx grd_s_ir_4_modelT[] = {
    gsSPTexture(0, 0, 0, 0, G_ON),
    gsDPSetCombineLERP(TEXEL1, 0, TEXEL0, TEXEL0, TEXEL1, 0, TEXEL0, 0, PRIMITIVE, 0, SHADE, COMBINED, 0, 0, 0, COMBINED),
    gsDPSetPrimColor(0, 255, 60, 120, 255, 255),
    gsDPSetRenderMode(G_RM_FOG_SHADE_A, G_RM_AA_ZB_XLU_SURF2),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave1_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 64, wave2_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 1, 0, GX_REPEAT, GX_CLAMP, 0, 0),
    gsSPDisplayList(0x0B000000),
    gsSPVertex(&grd_s_ir_4_v[195], 6, 0),
    gsSPNTrianglesInit_5b(
        4, // tri count
        0, 1, 2, // tri0
        1, 3, 4, // tri1
        1, 0, 3 // tri2
    ),
    gsSPNTriangles_5b(
        5, 0, 2, // tri0
        0, 0, 0, // tri1
        0, 0, 0, // tri2
        0, 0, 0 // tri3
    ),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave1_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 0, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsDPSetTextureImage_Dolphin(G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, wave3_tex_dummy),
    gsDPSetTile_Dolphin(G_DOLPHIN_TLUT_DEFAULT_MODE, 1, 0, GX_REPEAT, GX_REPEAT, 0, 0),
    gsSPDisplayList(0x0D000000),
    gsSPVertex(&grd_s_ir_4_v[201], 28, 0),
    gsSPNTrianglesInit_5b(
        27, // tri count
        0, 1, 2, // tri0
        3, 4, 1, // tri1
        0, 3, 1 // tri2
    ),
    gsSPNTriangles_5b(
        5, 6, 7, // tri0
        6, 8, 7, // tri1
        3, 9, 4, // tri2
        3, 10, 9 // tri3
    ),
    gsSPNTriangles_5b(
        10, 11, 9, // tri0
        10, 7, 11, // tri1
        7, 8, 11, // tri2
        6, 12, 8 // tri3
    ),
    gsSPNTriangles_5b(
        6, 13, 12, // tri0
        13, 14, 12, // tri1
        13, 15, 14, // tri2
        15, 16, 14 // tri3
    ),
    gsSPNTriangles_5b(
        16, 17, 14, // tri0
        16, 18, 17, // tri1
        16, 19, 18, // tri2
        15, 20, 16 // tri3
    ),
    gsSPNTriangles_5b(
        20, 21, 16, // tri0
        21, 19, 16, // tri1
        15, 22, 20, // tri2
        21, 23, 19 // tri3
    ),
    gsSPNTriangles_5b(
        23, 24, 19, // tri0
        23, 25, 24, // tri1
        25, 26, 24, // tri2
        26, 27, 24 // tri3
    ),
    gsSPEndDisplayList(),
};