#include <MarioKartWii/Item/ItemManager.hpp>
#include <MarioKartWii/Item/Obj/Kumo.hpp>
#include <MarioKartWii/Kart/KartMovement.hpp>
#include <MarioKartWii/RKNet/RKNetController.hpp>
#include <PulsarSystem.hpp>
#include <Settings/Settings.hpp>

namespace Pulsar {
namespace Race {
//Mega TC

void MegaTC(Kart::Movement& movement, int frames, int unk0, int unk1) {
    if((RKNet::Controller::sInstance->GetConnectionState() == RKNet::CONNECTIONSTATE_ROOM || Settings::Mgr::Get().GetSettingValue(Settings::SETTINGSTYPE_NEXUS, TOGGLE_MEGA_TC) == 1)) movement.ActivateMega();
    else movement.ApplyLightningEffect(frames, unk0, unk1);
}

kmCall(0x80580630, MegaTC);

void LoadCorrectTCBRRES(Item::ObjKumo& objKumo, const char* mdlName, const char* shadowSrc, u8 whichShadowListToUse,
    Item::Obj::AnmParam* anmParam) {
    if((RKNet::Controller::sInstance->GetConnectionState() == RKNet::CONNECTIONSTATE_ROOM || Settings::Mgr::Get().GetSettingValue(Settings::SETTINGSTYPE_NEXUS, TOGGLE_MEGA_TC) == 1)) objKumo.LoadGraphics("megaTC.brres", mdlName, shadowSrc, 1, anmParam,
        static_cast<nw4r::g3d::ScnMdl::BufferOption>(0), nullptr, 0);
    else objKumo.LoadGraphicsImplicitBRRES(mdlName, shadowSrc, 1, anmParam, static_cast<nw4r::g3d::ScnMdl::BufferOption>(0), nullptr);
}
kmCall(0x807af568, LoadCorrectTCBRRES);


}//namespace Race
}//namespace Pulsar