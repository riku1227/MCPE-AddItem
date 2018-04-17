#pragma once

#include <string>
#include <memory>
#include <functional>
#include <vector>
#include <unordered_map>

#include "CreativeItemCategory.h"

class TextureUVCoordinateSet;
//class CreativeItemCategory;
class UseAnimation;
class BlockShape;
class Block;
class ItemInstance;
class Color;
class Level;
class Player;
class BlockSource;
class Container;
class Vec3;
class Mob;
class Entity;
class IDataInput;
class IDataOutput;
class BlockPos;
class ItemUseCallback;
class TextureAtlas;
class BlockLegacy;
class ResourcePackManager;
class CompoundTag;

namespace Json {
  class Value;
}

namespace Documentation {
  class Writer;
}

class Item {
public:
  class Tier {
  public:

	void getTierItem() const;

  static void* GOLD;
  static void* IRON;
  static void* WOOD;
  static void* STONE;
  static void* DIAMOND;
  };
public:
  //void** vtable;
  void* field_1; //4
  void* field_2; //8
  void* field_3; //12
  void* field_4; //16
  void* field_5; //18
  void* field_6; //20
  void* field_7; //24
  void* field_8; //28
  void* field_9; //30
  void* field_10; //34
  void* field_11; //35
  void* field_12; //36
  void* field_13; //40
  void* field_14; //41
  void* field_15; //42
  void* field_16; //43
  void* field_17; //44
  void* field_18; //48
  void* field_19; //52
  void* field_20; //56
  void* field_21; //60
  void* field_22; //64
  void* field_23; //68
  void* field_24; //72
  void* field_25; //76
  void* field_26; //80
  void* field_27; //84
  void* field_28; //88
  void* field_29; //92
  void* field_30; //96
  void* field_31; //100
  void* field_32; //104
  void* field_33; //108
  void* field_34; //112
  void* field_35; //116

  Item(std::string const&, short);

  virtual ~Item();
  virtual void setIcon(std::string const&, int);
  virtual void setIcon(TextureUVCoordinateSet const&);
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
  virtual int /* ? */ getDamageChance(int) const;
  virtual void /* TODO */ uniqueAuxValues() const;
  virtual Color getColor(ItemInstance const&) const;
  virtual bool isTintable() const;
  virtual void use(ItemInstance&, Player&) const;
  virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char) const;
  virtual void useTimeDepleted(ItemInstance&, Level*, Player*) const;
  virtual void releaseUsing(ItemInstance&, Player*, int) const;
  virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
  virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
  virtual void mineBlock(ItemInstance&, Block const&, int, int, int, Entity*) const;
  virtual std::string buildDescriptionId(ItemInstance const&) const;
  virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
  virtual std::string buildCategoryDescriptionName(ItemInstance const&) const;
  virtual void readUserData(ItemInstance&, IDataInput&) const;
  virtual void writeUserData(ItemInstance const&, IDataOutput&) const;
  virtual int getMaxStackSize(ItemInstance const&) const;
  virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool) const;
  virtual void refreshedInContainer(ItemInstance&, Level&) const;
  virtual void* getCooldownType() const;
  virtual void* getCooldownTime() const;
  virtual void fixupOnLoad(ItemInstance&) const;
  virtual std::string getInteractText(Player const&) const;
  virtual int getAnimationFrameFor(Mob&, bool) const;
  virtual bool isEmissive(int) const;
  virtual TextureUVCoordinateSet& getIcon(int, int, bool) const;
  virtual int getIconYOffset() const;
  virtual bool isMirroredArt() const;
  virtual std::string getAuxValuesDescription() const;
  virtual bool _checkUseOnPermissions(Entity&, ItemInstance&, signed char const&, BlockPos const&) const;
  virtual void _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
  virtual void _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float, ItemUseCallback*) const;

  void setTextureAtlas(std::shared_ptr<TextureAtlas>);
  void resetDefaultLeatherColor();
  bool canUseSeed(Entity&, BlockPos, signed char) const;
  void setAllowOffhand(bool);
  void setIsMirroredArt(bool);
  void buildDocumentation(Documentation::Writer&);
  bool allowOffhand() const;
  void destroySpeedBonus(ItemInstance const&) const;
  void updateCustomBlockEntityTag(BlockSource&, ItemInstance&, BlockPos&) const;
  void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float, ItemUseCallback*) const;
  void buildDescriptionName(ItemInstance const&) const;


  static void initClientData();
  static void initCreativeItems(bool);
  static void addCreativeItem(ItemInstance const&);
  static Item* getItem(short);
  static void forEachItem(std::function<bool (Item const*)>);
  static Item* lookupByName(std::string const&, bool);
  static short findBlockItemId(BlockLegacy const&);
  static CreativeItemCategory findCreativeItem(ItemInstance const&);
  static std::shared_ptr<TextureAtlas> getTextureItem(std::string const&);
  static bool _textMatch(std::string const&, std::string const&, bool);
  static void initClient(Json::Value&, Json::Value&);
  static void initServer(Json::Value&);
  static void addBlockItems();
  static void registerItems(bool);
  static void teardownItems();
  static void initServerData(ResourcePackManager&);
  static void addCreativeItem(Item*, short);
  static void addCreativeItem(Block const&, short);
  static void addCreativeItem(short, short);
  static void endCreativeGroup();
  static void beginCreativeGroup(std::string const&, Block const*, short, CompoundTag const*);
  static void beginCreativeGroup(std::string const&, Item*, short, CompoundTag const*);
  static void beginCreativeGroup(std::string const&, ItemInstance const&);
  static void beginCreativeGroup(std::string const&, short, short, CompoundTag const*);
  static void initCreativeCategories();
  static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);
  static void setItem(short, Item*);
  static int toBlockId(short);

  static std::vector<ItemInstance> mCreativeList;
  static void* mCreativeListMutex;
  static std::unordered_map<std::string, std::unique_ptr<Item>> mItemLookupMap;
  static void* mExtraItems[4096]; //512
  static void* mCreativeGroups;
  static void* mCreativeGroupInfo;
  static void* mInvalidTextureUVCoordinateSet;
  static void* ICON_DESCRIPTION_PREFIX;
  static void* mItemTextureAtlas;
  static Item* mItems[4096]; //512

  static void* mSlimeBall;
  static void* mCarrot;
  static void* mSnowBall;
  static void* mFilledMap;
  static void* mBoots_iron;
  static void* mFishingRod;
  static void* mHelmet_iron;
  static void* mLeggings_iron;
  static void* mChestplate_iron;
  static void* mBow;
  static void* mSign;
  static void* mSkull;
  static void* mEnderpearl;
  static void* mSplash_potion;
  static void* mLingering_potion;
  static void* mExperiencePotionItem;
  static void* mEgg;
  static void* mEnderEye;
  static void* mEmerald;
  static void* mCarrotOnAStick;
  static void* mTrident;
  static void* mClock;
  static void* mBanner;
  static void* mCompass;
  static void* mTotem;
  static void* mGlass_bottle;
  static void* mHoe_stone;
  static void* mItemFrame;
  static void* mMobPlacer;
  static void* mRecordCat;
  static void* mRecordFar;
  static void* mApple_gold;
  static void* mFireCharge;
  static void* mRecordMall;
  static void* mRecordStal;
  static void* mRecordWait;
  static void* mRecordWard;
  static void* mSword_gold;
  static void* mSword_iron;
  static void* mSword_wood;
  static void* mHoe_diamond;
  static void* mRecordChirp;
  static void* mRecordStrad;
  static void* mShovel_gold;
  static void* mShovel_iron;
  static void* mShovel_wood;
  static void* mSword_stone;
  static void* mRecordBlocks;
  static void* mShovel_stone;
  static void* mFlintAndSteel;
  static void* mRecordMellohi;
  static void* mSword_diamond;
  static void* mWritable_book;
  static void* mShovel_diamond;
  static void* mApple_enchanted;
  static void* mBed;
  static void* mReeds;
  static void* mBucket;
  static void* mPotion;
  static void* mString;
  static void* mEmptyMap;
  static void* mHoe_gold;
  static void* mHoe_iron;
  static void* mHoe_wood;
  static void* mPainting;
  static void* mRecord11;
  static void* mRecord13;
  static void* mRedStone;
  static void* mArrow;
  static void* mDiamond;
  static void* mArmorStand;
  static void* mEndCrystal;
  static void* mTNTMinecart;
  static void* mChestMinecart;
  static void* mHopperMinecart;
  static void* mCommandBlockMinecart;
  static void* mBoat;
  static void* mMinecart;
  static void* mDye_powder;
  static void* mPaper;
  static void* mGoldIngot;
  static void* mIronIngot;
  static void* mBeef_cooked;
  static void* mGold_nugget;
  static void* mIron_nugget;
  static void* mNetherbrick;
  static void* mPotatoBaked;
  static void* mNetherQuartz;
  static void* mRabbitCooked;
  static void* mMutton_cooked;
  static void* mChicken_cooked;
  static void* mFish_cooked_cod;
  static void* mPorkChop_cooked;
  static void* mFish_cooked_salmon;
  static void* mCoal;
  static void* mBrick;
  static void* mLead;
  static void* mBread;
  static void* mWheat;
  static void* mPotato;
  static void* mGoldHorseArmor;
  static void* mIronHorseArmor;
  static void* mDiamondHorseArmor;
  static void* mLeatherHorseArmor;
  static void* mSaddle;
  static void* mHopper;
  static void* mEnchanted_book;
  static void* mHelmet_leather;
  static void* mSeeds_wheat;
  static void* mSeeds_beetroot;
  static void* mBeetroot;
  static void* mRotten_flesh;
  static void* mGenerateDenyParticleEffect;
  static void* mGhast_tear;
  static void* mRabbitFoot;
  static void* mSpider_eye;
  static void* mYellowDust;
  static void* mBlazePowder;
  static void* mMagma_cream;
  static void* mNether_wart;
  static void* mGoldenCarrot;
  static void* mDragon_breath;
  static void* mSpeckled_melon;
  static void* mFish_raw_pufferfish;
  static void* mFermented_spider_eye;
  static void* mSugar;
  static void* mSulphur;
  static void* mBoots_gold;
  static void* mBoots_chain;
  static void* mHelmet_gold;
  static void* mHelmet_chain;
  static void* mBoots_diamond;
  static void* mBoots_leather;
  static void* mLeggings_gold;
  static void* mHelmet_diamond;
  static void* mLeggings_chain;
  static void* mChestplate_gold;
  static void* mChestplate_chain;
  static void* mLeggings_diamond;
  static void* mLeggings_leather;
  static void* mChestplate_diamond;
  static void* mChestplate_leather;
  static void* mElytra;
  static void* mLeather;
  static void* mWritten_book;
  static void* mFireworksItem;
  static void* mFireworkCharge;
  static void* mFeather;
  static void* mRabbitRaw;
  static void* mMutton_raw;
  static void* mChicken_raw;
  static void* mChorusFruit;
  static void* mFish_raw_cod;
  static void* mHatchet_gold;
  static void* mHatchet_iron;
  static void* mPickAxe_gold;
  static void* mPickAxe_iron;
  static void* mPorkChop_raw;
  static void* mFish_raw_salmon;
  static void* mChorusFruitPopped;
  static void* mClay;
  static void* mBeef_raw;
  static void* mBook;
  static void* mBowl;
  static void* mStick;
  static void* mHatchet_wood;
  static void* mPickAxe_wood;
  static void* mDoor_iron;
  static void* mDoor_wood;
  static void* mFlowerPot;
  static void* mChalkboard;
  static void* mComparator;
  static void* mDoor_birch;
  static void* mMelonSlice;
  static void* mNetherStar;
  static void* mPumpkinPie;
  static void* mRabbitHide;
  static void* mRabbitStew;
  static void* mDoor_acacia;
  static void* mDoor_jungle;
  static void* mDoor_spruce;
  static void* mSeeds_melon;
  static void* mBeetrootSoup;
  static void* mDoor_darkoak;
  static void* mMushroomStew;
  static void* mShulkerShell;
  static void* mBrewing_stand;
  static void* mHatchet_stone;
  static void* mPickAxe_stone;
  static void* mPortfolioBook;
  static void* mSeeds_pumpkin;
  static void* mHatchet_diamond;
  static void* mInCreativeGroup;
  static void* mPickAxe_diamond;
  static void* mPrismarineShard;
  static void* mPoisonous_potato;
  static void* mAllowExperimental;
  static void* mFish_raw_clownfish;
  static void* mPrismarineCrystals;
  static void* mBone;
  static void* mCake;
  static void* mApple;
  static void* mFlint;
  static void* mCamera;
  static void* mCookie;
  static void* mShears;
  static void* mNameTag;
  static void* mBlazeRod;
  static void* mCauldron;
  static void* mRepeater;
};
