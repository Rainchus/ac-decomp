extern aFTR_rig_c aNogKera_key_anime_data;
static void fNgKr_mv(FTR_ACTOR* ftr_actor, ACTOR* my_room_actor, GAME* game, u8* data);

static aFTR_vtable_c fNgKr_func = {
	NULL,
	&fNgKr_mv,
	NULL,
	NULL,
	NULL,
};

aFTR_PROFILE iam_nog_kera = {
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	&aNogKera_key_anime_data,
	NULL,
	30.0f,
	0.01f,
	aFTR_SHAPE_TYPEA,
	mCoBG_FTR_TYPEA,
	0,
	2,
	0,
	aFTR_INTERACTION_INSECT,
	&fNgKr_func,
};