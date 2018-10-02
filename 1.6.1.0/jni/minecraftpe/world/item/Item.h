#pragma once

#include <string>
#include <memory>

#include "CreativeItemCategory.h"

//class CreativeItemCategory;
class UseAnimation;
class BlockShape;
class Block;
class ItemInstance;
class Level;
class Color;
class Player;
class BlockSource;
class Container;
class Vec3;
class Mob;
class Actor;
class IDataInput;
class IDataOutput;
class CooldownType;
class TextureUVCoordinateSet;
class BlockPos;
class ItemUseCallback;
class TextureAtlas;
class TextureAtlasItem;
class CompoundTag;

namespace Json {
  class Value;
}

class Item {
public:
  void* field_1;
  void* field_2;
  void* field_3;
  void* field_4;
  void* field_5;
  void* field_6;
  void* field_7;
  void* field_8;
  void* field_9;
  void* field_10;
  void* field_11;
  void* field_12;
  void* field_13;
  void* field_14;
  void* field_15;
  void* field_16;
  void* field_17;
  void* field_18;
  void* field_19;
  void* field_20;
  void* field_21;
  void* field_22;
  void* field_23;
  void* field_24;
  void* field_25;
  void* field_26;
  void* field_27;
  void* field_28;
  void* field_29;
  void* field_30;
  void* field_31;
  void* field_32;
  void* field_33;

  Item(std::string const&, short);
  virtual ~Item();
  
  virtual void setMaxStackSize(unsigned char);
  virtual void setCategory(CreativeItemCategory);
  virtual void setStackedByData(bool);
  virtual void setMaxDamage(int);
  virtual void setHandEquipped();
  virtual void setUseAnimation(UseAnimation);
  virtual void setMaxUseDuration(int);
  virtual void setRequiresWorldBuilder(bool);
  virtual void setExplodable(bool);
  virtual void setIsGlint(bool);
  virtual void setShouldDespawn(bool);
  virtual BlockShape getBlockShape() const;
  virtual bool canBeDepleted() const;
  virtual bool canDestroySpecial(Block const&) const;
  virtual int getLevelDataForAuxValue(int) const;
  virtual bool isStackedByData() const;
  virtual int getMaxDamage() const;
  virtual int getAttackDamage() const;
  virtual bool isHandEquipped() const;
  virtual bool isArmor() const;
  virtual bool isDye() const;
  virtual bool isGlint(ItemInstance const&) const;
  virtual bool isThrowable() const;
  virtual bool showsDurabilityInCreative() const;
  virtual bool canDestroyInCreative() const;
  virtual bool isDestructive(int) const;
  virtual bool isLiquidClipItem(int) const;
  virtual bool requiresInteract() const;
  virtual void appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
  virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&) const;
  virtual int getEnchantSlot() const;
  virtual int getEnchantValue() const;
  virtual int getArmorValue() const;
  virtual bool isComplex() const;
  virtual bool isValidAuxValue(int) const;
  virtual int getDamageChance(int) const;
  virtual int uniqueAuxValues() const;
  virtual Color getColor(ItemInstance const&) const;
  virtual bool isTintable() const;
  virtual void use(ItemInstance&, Player&) const;
  virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char) const;
  virtual void useTimeDepleted(ItemInstance&, Level*, Player*) const;
  virtual void releaseUsing(ItemInstance&, Player*, int) const;
  virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
  virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
  virtual void mineBlock(ItemInstance&, Block const&, int, int, int, Actor*) const;
  virtual std::string buildDescriptionId(ItemInstance const&) const;
  virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
  virtual std::string buildCategoryDescriptionName(ItemInstance const&) const;
  virtual void* readUserData(ItemInstance&, IDataInput&) const;
  virtual void* writeUserData(ItemInstance const&, IDataOutput&) const;
  virtual int getMaxStackSize(ItemInstance const&) const;
  virtual void inventoryTick(ItemInstance&, Level&, Actor&, int, bool) const;
  virtual void refreshedInContainer(ItemInstance&, Level&) const;
  virtual CooldownType getCooldownType() const;
  virtual int getCooldownTime() const;
  virtual void fixupOnLoad(ItemInstance&) const;
  virtual int getDamageValue(ItemInstance const&) const;
  virtual bool isSameItem(ItemInstance const&, ItemInstance const&) const;
  virtual std::string getInteractText(Player const&) const;
  virtual int getAnimationFrameFor(Mob&, bool) const;
  virtual bool isEmissive(int) const;
  virtual TextureUVCoordinateSet& getIcon(int, int, bool) const;
  virtual int getIconYOffset() const;
  virtual void setIcon(std::string const&, int);
  virtual void setIcon(TextureUVCoordinateSet const&);
  virtual std::string getAuxValuesDescription() const;
  virtual bool _checkUseOnPermissions(Actor&, ItemInstance&, signed char const&, BlockPos const&) const;
  virtual bool _calculatePlacePos(ItemInstance&, Actor&, signed char&, BlockPos&) const;
  virtual void _useOn(ItemInstance&, Actor&, BlockPos, signed char, float, float, float, ItemUseCallback*) const;

  void setTextureAtlas(std::shared_ptr<TextureAtlas>);
  bool isMirroredArt() const;
  bool canUseSeed(Actor&, BlockPos, signed char) const;
  void setAllowOffhand(bool);
  void setIsMirroredArt(bool);
  std::string getFullName() const;
  bool allowOffhand() const;
  std::string getNamespace() const;
  void destroySpeedBonus(ItemInstance const&) const;
  std::string getSerializedName() const;
  std::string buildDescriptionName(ItemInstance const&) const;
  void updateCustomBlockEntityTag(BlockSource&, ItemInstance&, BlockPos&) const;
  void useOn(ItemInstance&, Actor&, int, int, int, signed char, float, float, float, ItemUseCallback*) const;

  static void addCreativeItem(ItemInstance const&);
  static void initCreativeItems(bool, std::function<void ()>);
  static void findCreativeItem(ItemInstance const&);
  static Item* getTextureItem(std::string const&);
  static TextureUVCoordinateSet* getIconTextureUVSet(TextureAtlasItem const&, int, int);
  static bool _textMatch(std::string const&, std::string const&, bool);
  static void initClient(Json::Value&, Json::Value&);
  static void initServer(Json::Value&);
  static void addCreativeItem(Item*, short);
  static void addCreativeItem(Block const&, short);
  static void addCreativeItem(short, short);
  static void endCreativeGroup();
  static void beginCreativeGroup(std::string const&, Block const*, short, CompoundTag const*);
  static void beginCreativeGroup(std::string const&, Item*, short, CompoundTag const*);
  static void beginCreativeGroup(std::string const&, ItemInstance const&);
  static void beginCreativeGroup(std::string const&, short, short, CompoundTag const*);
  static TextureUVCoordinateSet& getTextureUVCoordinateSet(std::string const&, int);
  static int toBlockId(short);

  static void* mCreativeList;
  static void* mCreativeListMutex;
  static void* mCreativeGroups;
  static void* mCreativeGroupInfo;
  static void* mGenerateDenyParticleEffect;
  static void* mInvalidTextureUVCoordinateSet;
  static void* mInCreativeGroup;
  static void* mItemTextureAtlas;
  static void* mAllowExperimental;
  static void* ICON_DESCRIPTION_PREFIX;
};