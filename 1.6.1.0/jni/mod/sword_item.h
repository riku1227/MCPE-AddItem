#pragma once

#include "minecraftpe/world/item/Item.h"

class SwordItem : public Item {
public:
  SwordItem(std::string const&, short);

  virtual bool canDestroySpecial(Block const&) const;
  virtual int getAttackDamage() const;
  virtual bool canDestroyInCreative() const;
  virtual void appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
  virtual int getEnchantSlot() const;
  virtual int getEnchantValue() const;
  virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
  virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
  virtual void mineBlock(ItemInstance&, Block const&, int, int, int, Actor*) const;
};