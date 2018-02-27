#include "sword_item.h"

SwordItem::SwordItem(std::string const& name,int id) : Item(name,id) {
  setMaxStackSize(1);
  setCategory(CreativeItemCategory::EQUIPMENT);
  setMaxDamage(888);
  setHandEquipped();
}

int SwordItem::getAttackDamage() const {
  return 8;
}

bool SwordItem::canDestroyInCreative() const {
  return false;
}

int SwordItem::getEnchantSlot() const {
  return 16;
}

int SwordItem::getEnchantValue() const {
  return 35;
}

float SwordItem::getDestroySpeed(ItemInstance const& item, Block const& block) const {
    return mSword_iron -> getDestroySpeed(item,block);
}

void SwordItem::hurtEnemy(ItemInstance& item, Mob* mob1, Mob* mob2) const {
    //item.hurtAndBreak(1,mob1);
}

void SwordItem::mineBlock(ItemInstance& item, BlockID blockID, int x, int y, int z, Entity* entity) const {
    //item.hurtAndBreak(2,entity);
}