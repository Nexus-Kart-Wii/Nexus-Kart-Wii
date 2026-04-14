#include <kamek.hpp>
#include <MarioKartWii/UI/Page/Other/GlobeSearch.hpp>
#include <PulsarSystem.hpp>
#include <UI/UI.hpp>

kmWrite32(0x80609268, 0x7f63db78);
namespace Pulsar {
namespace UI {

void PatchGlobeSearchBMG(Pages::GlobeSearch* globeSearch) {
    globeSearch->countdown.Update();
    if(System::sInstance->netMgr.deniesCount >= 3) globeSearch->messageWindow.LayoutUIControl::SetMessage(UI::BMG_TOO_MANY_DENIES);
}
kmCall(0x8060926c, PatchGlobeSearchBMG);

//Remove WW Button [Chadderz]
kmWrite16(0x8064B982, 0x00000005);
kmWrite32(0x8064BA10, 0x60000000);
kmWrite32(0x8064BA38, 0x60000000);
kmWrite32(0x8064BA50, 0x60000000);
kmWrite32(0x8064BA5C, 0x60000000);
kmWrite16(0x8064BC12, 0x00000001);
kmWrite16(0x8064BC3E, 0x00000484);
kmWrite16(0x8064BC4E, 0x000010D7);
kmWrite16(0x8064BCB6, 0x00000484);
kmWrite16(0x8064BCC2, 0x000010D7);


}//namespace UI
}//namespace Pulsar