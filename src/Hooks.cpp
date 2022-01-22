#include "Hooks.h"

#include "Settings.h"

#include "RE/Skyrim.h"
#include "REL/Relocation.h"
#include "SKSE/API.h"
#include "SKSE/Trampoline.h"


namespace Hooks
{
	void Hook_WorldPtToScreenPt3(RE::NiCamera* a_camera, RE::NiPoint3& a_in, float& a_xOut, float& a_yOut, float& a_zOut, float a_zeroTolerance)
	{
		if (Settings::enabled) {
			a_in.z = static_cast<float>(Settings::markerHeight);
		}
		RE::NiCamera::WorldPtToScreenPt3(a_camera->worldToCam, a_camera->port, a_in, a_xOut, a_yOut, a_zOut, a_zeroTolerance);
	}


	void Install()
	{
		REL::Relocation<std::uintptr_t> target(REL::ID(52226), 0x22F); //REL::Relocation<std::uintptr_t> target(REL::ID(52224), 0x22F);
		auto& trampoline = SKSE::GetTrampoline();
		trampoline.write_call<5>(target.address(), &Hook_WorldPtToScreenPt3);
		logger::info("Installed all hooks AE version"sv);
	}
};
