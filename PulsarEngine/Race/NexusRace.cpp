#include <kamek.hpp>

//AirFIBs [Conradi]
kmWrite32(0x808a5770, 0x00000000);
kmWrite32(0x808a5774, 0x00000000);

//Enhanced Pause Menu [Ro]
kmWrite32(0x8062c658, 0x38800019);
kmWrite32(0x8062c79c, 0x38800019);
kmWrite32(0x80633a98, 0x38600019);
kmWrite32(0x8062c8e0, 0x38800019);
kmWrite32(0x80633970, 0x38600019);
kmWrite32(0x8083d618, 0x60000000);


extern "C" void sInstance__8Racedata(void*);
extern "C" void sInstance__10SectionMgr(void*);
asmFunc EnhancedPauseMenu1() {
  ASM(
  lwz r3, sInstance__10SectionMgr@l (r6);
  lwz r12, sInstance__8Racedata@l (r6);
  lwz r0, 0x1760 (r12);
  cmpwi r0, 2;
  beq end;

  cmpwi r4, 0x49;
  beq decreaseRaceNum;

  cmpwi r4, 0x4A;
  bne end;

  li r4, 0x4B;

  cmpwi r0, 1;
  beq decreaseRaceNum;

  li r4, 0x4C;

  decreaseRaceNum:
  lwz r6, 0x98 (r3);
  lwz r31, 0x60 (r6);
  subi r31, r31, 1;
  stw r31, 0x60 (r6);

  li r31, 5;
  stw r31, 0x1764 (r12);

  end:
  mr r31, r5;
  blr;
  )
}
kmCall(0x806024d8, EnhancedPauseMenu1);

extern "C" void sInstance__8Racedata(void*);
asmFunc EnhancedPauseMenu2() {
  ASM(
  lis r3, sInstance__8Racedata@ha;
  lwz r3, sInstance__8Racedata@l (r3);
  lwz r4, 0x1760 (r3);
  cmpwi r4, 2;
  beq end;
  li r4, 0x1;
  stw r4, 0xD18 (r3);
  stw r4, 0xE08 (r3);
  stw r4, 0xEF8 (r3);

  end:
  li        r3, 0x6C4;
  blr;
  )
}
kmCall(0x80623df4, EnhancedPauseMenu2);

kmWrite32(0x80859068, 0x48000808);
kmWrite32(0x80858e38, 0x48000040);


//Hybrid Drift v2 [CLF78, Ismy]
asmFunc HybridDrift2() {
    ASM(
  lwz r0, 0x14(r3);
  lwz r12, 0(r28);
  lwz r12, 0(r12);
  lwz r12, 0x14(r12);
  lwz r12, 0(r12);
  lwz r12, 0x4(r12);
  cmpwi r12, 2;
  beqlr;
  cmpwi r12, 0;
  beq slideissue;
  lwz r3, 4 (r3);
  andis. r3, r3, 0x1000;
  bnelr;
  slideissue:
  li r0, 0;
  blr;
    )
}
kmCall(0x8057930C, HybridDrift2);
kmCall(0x80578DCC, HybridDrift2);

asmFunc HybridDrift3() {
    ASM(
lwz r0, 0x14(r3);
rlwinm. r12, r0, 0, 18, 18;
beq end2;
ori r0, r0, 0x10;
stw r0, 0x14(r3);
end2:
lwz r0, 0x4(r3);
blr;
    )
}
kmCall(0x8057DFA8, HybridDrift3);

asmFunc HybridDrift4() {
    ASM(
lwz r0, 0x14(r4);
rlwinm. r12, r0, 0, 18, 18;
beq end2;
ori r0, r0, 0x10;
stw r0, 0x14(r4);
end2:
lwz r0, 0x4(r4);
blr;
    )
}
kmCall(0x8057E018, HybridDrift4);

asmFunc HybridDrift6() {
    ASM(
  rlwinm.   r0,r0,0,27,27;
  li        r0, 0;
  stw       r0, 0x1C8(r3);
    )
}
kmCall(0x8057E108, HybridDrift6);

asmFunc HybridDrift7() {
    ASM(
lwz r3, 0x4(r30);
andi. r4, r3, 0x84;
beq end;
lwz r4, 0x14(r30);
rlwinm r4, r4, 0, 28, 26;
stw r4, 0x14(r30);
rlwinm r3, r3, 0, 4, 2;
stw r3, 0x4(r30);
end:
mr r3, r30;
blr;
    )
}
kmCall(0x80594AA8, HybridDrift7);
kmWrite8(0x8059450E, 0x00000020);
kmWrite32(0x80594A60, 0x60000000);
kmWrite32(0x805A35BC, 0x38600000);
kmWrite16(0x80745AB0, 0x00004800);
kmWrite16(0x808CB70A, 0x00000000);