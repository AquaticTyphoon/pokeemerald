Scarlet_Bay_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Scarlet_Bay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE
	.byte 0

Scarlet_Bay_MapScripts_MAP_SCRIPT_ON_FRAME_TABLE:
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
	setvar VAR_DEMO_STATE, 1
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_B_DASH
	random 3
	switch VAR_RESULT
	case 0, Demo_Start_2
	case 1, Demo_Start_3
	case 2, Demo_Start_4
	return

Demo_Start_2:
	call StarterOne
	return

Demo_Start_3:
	call StarterTwo
	return

Demo_Start_4:
	call StarterThree
	return


StarterOne::
	showmonpic SPECIES_TREECKO, 10, 3
	msgbox StarterOne_Text_0
	givemon SPECIES_TREECKO, 5, ITEM_ORAN_BERRY
	call NicknamePartyMon
	return


StarterTwo::
	showmonpic SPECIES_TORCHIC, 10, 3
	msgbox StarterTwo_Text_0
	givemon SPECIES_TORCHIC, 5, ITEM_ORAN_BERRY
	call NicknamePartyMon
	return


StarterThree::
	showmonpic SPECIES_MUDKIP, 10, 3
	msgbox StarterThree_Text_0
	givemon SPECIES_MUDKIP, 5, ITEM_ORAN_BERRY
	call NicknamePartyMon
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

StarterOne_Text_0:
	.string "{PLAYER} recieved a Treeko!$"

StarterTwo_Text_0:
	.string "{PLAYER} recieved a Torchic!$"

StarterThree_Text_0:
	.string "{PLAYER} recieved a Mudkip!$"

NicknamePartyMon_Text_0:
	.string "Do you want to nickname your starter?$"
