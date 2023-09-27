
#pragma once

#ifndef BLOODHUNT_H

#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#include <iostream>
#include <dwmapi.h>
#include  <d3d9.h>
#include  <d3dx9.h>

#include "singleton.h"
#include "vector.h"
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dwmapi.lib")


inline namespace BloodHunt
{
	class Variables : public Singleton<Variables>
	{
	public:
		const char* dwProcessName = "SolarlandClient-Win64-Shipping.exe";
		DWORD dwProcessId = NULL;
		uint64_t dwProcess_Base = NULL;
		HWND gameHWND = NULL;

		int actor_count = NULL;
		int ScreenHeight = NULL;
		int ScreenWidth = NULL;
		int ScreenLeft = NULL;
		int ScreenRight = NULL;
		int ScreenTop = NULL;
		int ScreenBottom = NULL;

		float ScreenCenterX = ScreenWidth / 2;
		float ScreenCenterY = ScreenHeight / 2;

		DWORD_PTR game_instance = NULL;
		DWORD_PTR u_world = NULL;
		DWORD_PTR local_player_pawn = NULL;
		DWORD_PTR local_player_array = NULL;
		DWORD_PTR local_player = NULL;
		DWORD_PTR local_player_root = NULL;
		DWORD_PTR local_player_controller = NULL;
		DWORD_PTR local_player_state = NULL;
		DWORD_PTR persistent_level = NULL;
		DWORD_PTR actors = NULL;
		DWORD_PTR ranged_weapon_component = NULL;
		DWORD_PTR equipped_weapon_type = NULL;


	};
#define GameVars BloodHunt::Variables::Get()

	class Offsets : public Singleton<Offsets>
	{
	public:

        //GWorld
        DWORD offset_u_world = 0x6807900; // old: 0x675FBB0

        //GNames
        DWORD offset_g_names = 0x6697E00; // old: 0x65F0180

        //CameraManager
        DWORD offset_camera_manager = 0x2d8; // APlayerController->PlayerCameraManager

        //CameraCache
        DWORD offset_camera_cache = 0x1bf0; //APlayerCameraManager->CameraCachePrivate

        //PersistentLevel
        DWORD offset_persistent_level = 0x30; //UWorld->PersistentLevel

        //OwningGameInstance
        DWORD offset_game_instance = 0x220; //UWolrd->OwningGameInstance  //old: 0x0220 old2: 0x1A0

        //LocalPlayers
        DWORD offset_local_players_array = 0x38; //UGameInstance->LocalPlayers

        //PlayerController
        DWORD offset_player_controller = 0x30; //UPlayer->PlayerController

        //AcknowledgePawn
        DWORD offset_apawn = 0x2c0;  //APlayerController->AcknowledgedPawn

        //RootComponent
        DWORD offset_root_component = 0x138; //AActor->RootComponent

        //ActorArray
        DWORD offset_actor_array = 0x98; //UNetConnection->OwningActor

        //oActorCount
        DWORD offset_actor_count = 0xa0; //UNetConnection->MaxPacket

        //AActorID
        DWORD offset_actor_id = 0x18;

        //PlayerNamePrivate
        DWORD offset_player_name = 0x310;

        //oPlayerState
        DWORD offset_player_state = 0x248; //APawn->PlayerState

        //ActorMesh
        DWORD offset_actor_mesh = 0x288; //ACharacter->Mesh

        //BoneArray
        DWORD offset_bone_array = 0x598;

        //ComponentToWorld
        DWORD offset_component_to_world = 0x250;


        DWORD offset_ranged_weapon_component = 0x4c8;

        //WeaponType
        DWORD offset_equipped_weapon_type = 0x36d; //old: 0x170

        //RelativeLocation
        DWORD offset_relative_location = 0x11c;


        DWORD offset_last_submit_time = 0x288;
        DWORD offset_last_render_time = 0x28C;

        //oHealth
        DWORD offset_health = 0x580;

        //oMaxHealth
        DWORD offset_max_health = 0x584;


        DWORD offset_BodyType = 0x7a4;

        DWORD offset_RecoilComponent = 0x0598;

        DWORD offset_WeaponConfig = 0x00D0;

        DWORD offset_is_same_team = 0xa70;

        DWORD offset_solaranimstate = 0x7a0;

        DWORD offset_gamejobmanager = 0x228;

        DWORD offset_CachedCurrentWeapon = 0x1A30; //ASolarCharacter->CachedCurrentWeapon

        DWORD RecoilComponent = 0x0598; //ASolarWeapon->RecoilComponent


        DWORD CachedCurrentWeapon = 0x1A30; //ASolarCharacter->CachedCurrentWeapon
	};

#define GameOffset BloodHunt::Offsets::Get()
}
#endif  !BLOODHUNT_H

