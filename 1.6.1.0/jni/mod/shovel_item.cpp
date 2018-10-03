#include "shovel_item.h"

#include "minecraftpe/world/item/VanillaItems.h"
#include "minecraftpe/client/recourses/I18n.h"

ShovelItem::ShovelItem(std::string const& nameId, short id) : Item(nameId, id) {
  setMaxStackSize(1);
  setCategory(CreativeItemCategory::EQUIPMENT);
  setMaxDamage(472);
  setHandEquipped();
}

bool ShovelItem::canDestroySpecial(Block const& block) const {
  return VanillaItems::mShovel_iron -> canDestroySpecial(block);
}

int ShovelItem::getAttackDamage() const {
  return 7;
}

void ShovelItem::appendFormattedHovertext(ItemInstance const& item, Level& level, std::string& str, bool b) const {
  Item::appendFormattedHovertext(item, level, str, b);

  /*
    TODO
    Fix hard code
  */
  str += "\n\n§9+7 "+ I18n::get("attribute.name.generic.attackDamage");
}

int ShovelItem::getEnchantSlot() const {
  return VanillaItems::mShovel_iron -> getEnchantSlot();
}

int ShovelItem::getEnchantValue() const {
  return 60;
}

float ShovelItem::getDestroySpeed(ItemInstance const& item, Block const& block) const {
  float speed = VanillaItems::mShovel_iron -> getDestroySpeed(item, block);
  /*
    TODO
    Support enchant
  */
  if(speed >= 1.1) {
    return 10;
  }
}

void ShovelItem::hurtEnemy(ItemInstance& item, Mob* mob1, Mob* mob2) const {
  VanillaItems::mShovel_iron -> hurtEnemy(item, mob1, mob2);
}

void ShovelItem::mineBlock(ItemInstance& item, Block const& block, int x, int y, int z, Actor* actor) const {
  VanillaItems::mShovel_iron -> mineBlock(item, block, x, y, z, actor);
}

/* void ShovelItem::_useOn(ItemInstance& item, Actor& actor, BlockPos pos, signed char side, float xx, float yy, float zz, ItemUseCallback* callback) const {
} */