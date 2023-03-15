LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

LittlerootTown_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
	map_script_2 VAR_DEMO_STATE, 0, Demo_Start
	.2byte 0


DebugSignTest::
	lockall
	msgbox DebugSignTest_Text_0
	releaseall
	return


Demo_Start::
	lockall
	playfanfare MUS_OBTAIN_ITEM
	msgbox Demo_Start_Text_0
	givemon SPECIES_MUDKIP, 5, ITEM_ORAN_BERRY
	call NicknamePartyMon
	setvar VAR_DEMO_STATE, 1
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_SYS_POKEMON_GET
	return


NicknamePartyMon::
	msgbox NicknamePartyMon_Text_0, MSGBOX_YESNO
	hidemonpic
	compare VAR_RESULT, YES
	goto_if_eq NicknamePartyMon_2
NicknamePartyMon_1:
	releaseall
	return

NicknamePartyMon_2:
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto NicknamePartyMon_1


DebugSignTest_Text_0:
	.string "Big Chungus$"

Demo_Start_Text_0:
	.string "{PLAYER} Recieved Mudkip$"

NicknamePartyMon_Text_0:
	.string "Give your starter a name?$"
