#pragma once

#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

#include "CreativeItemCategory.h"

class BlockID {};
class UseAnimation;
class TextureUVCoordinateSet;
class Block;
class ItemInstance;
class Level;
class Color;
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
class ResourcePackManager;
class CompoundTag;
class DocumentationSystem;

namespace Json {
  class Value;
}

class Item {
public:
  class Tier {
  public:
    void getTierItem() const;

    static Tier* GOLD;
    static Tier* IRON;
    static Tier* WOOD;
    static Tier* STONE;
    static Tier* DIAMOND;
};
public:
  //void** vtable;
  void* field_1; //4
  void* field_2; //8 atlas.items(?)
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
  void* field_14; //44
  void* field_15; //45
  void* field_16; //48
  void* field_17; //52
  void* field_18; //60
  void* field_19; //64
  void* field_20; //68
  void* field_21; //72
  void* field_22; //76
  void* field_23; //80
  void* field_24; //88
  void* field_25; //96
  void* field_26; //104
  void* field_27; //254
  void* field_28; //256
  void* field_29; //257

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
  virtual void* getBlockShape() const;
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
  virtual std::string appendFormattedHovertext(ItemInstance const&, Level&, std::string&, bool) const;
  virtual bool isValidRepairItem(ItemInstance const&, ItemInstance const&) const;
  virtual int getEnchantSlot() const;
  virtual int getEnchantValue() const;
  virtual bool isComplex() const;
  virtual bool isValidAuxValue(int) const;
  virtual void getDamageChance(int) const;
  virtual bool uniqueAuxValues() const;
  virtual Color getColor(ItemInstance const&) const;
  virtual bool isTintable() const;
  virtual void use(ItemInstance&, Player&) const;
  virtual void dispense(BlockSource&, Container&, int, Vec3 const&, signed char) const;
  virtual void useTimeDepleted(ItemInstance&, Level*, Player*) const;
  virtual void releaseUsing(ItemInstance&, Player*, int) const;
  virtual float getDestroySpeed(ItemInstance const&, Block const&) const;
  virtual void hurtEnemy(ItemInstance&, Mob*, Mob*) const;
  virtual void mineBlock(ItemInstance&, BlockID, int, int, int, Entity*) const;
  virtual std::string buildDescriptionId(ItemInstance const&) const;
  virtual std::string buildEffectDescriptionName(ItemInstance const&) const;
  virtual std::string buildCategoryDescriptionName(ItemInstance const&) const;
  virtual void readUserData(ItemInstance&, IDataInput&) const;
  virtual void writeUserData(ItemInstance const&, IDataOutput&) const;
  virtual int getMaxStackSize(ItemInstance const&) const;
  virtual void inventoryTick(ItemInstance&, Level&, Entity&, int, bool) const;
  virtual void refreshedInContainer(ItemInstance&, Level&) const;
  virtual int getCooldownType() const;
  virtual int getCooldownTime() const;
  virtual void fixupOnLoad(ItemInstance&) const;
  virtual std::string getInteractText(Player const&) const;
  virtual int getAnimationFrameFor(Mob&, bool) const;
  virtual bool isEmissive(int) const;
  virtual TextureUVCoordinateSet getIcon(int, int, bool) const;
  virtual int getIconYOffset() const;
  virtual bool isMirroredArt() const;
  virtual std::string getAuxValuesDescription() const;
  virtual void _checkUseOnPermissions(Entity&, ItemInstance&, signed char const&, BlockPos const&) const;
  virtual void _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
  virtual void _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float, ItemUseCallback*) const;

  void setTextureAtlas(std::shared_ptr<TextureAtlas>);
  bool canUseSeed(Entity&, BlockPos, signed char) const;
  std::string lookupByName(std::string const&, bool);
  void findCreativeItem(ItemInstance const&);
  void* getTextureItem(std::string const&);
  void _textMatch(std::string const&, std::string const&, bool);
  void initClient(Json::Value&, Json::Value&);
  void initServer(Json::Value&);
  void initServerData(ResourcePackManager&);
  void setAllowOffhand(bool);
  void endCreativeGroup();
  void setIsMirroredArt(bool);
  bool allowOffhand() const;
  void destroySpeedBonus(ItemInstance const&) const;
  void buildDescriptionName(ItemInstance const&) const;
  void updateCustomBlockEntityTag(BlockSource&, ItemInstance&, BlockPos&) const;
  void useOn(ItemInstance&, Entity&, int, int, int, signed char, float, float, float, ItemUseCallback*) const;

  static void initClientData();
  static void initCreativeItems();
  static void addCreativeItem(ItemInstance const&);
  static void addBlockItems();
  static void registerItems();
  static void teardownItems();
  static void addCreativeItem(Block const*, short);
  static void addCreativeItem(Item*, short);
  static void addCreativeItem(short, short);
  static void beginCreativeGroup(std::string const&, Block const*, short, CompoundTag const*);
  static void beginCreativeGroup(std::string const&, Item*, short, CompoundTag const*);
  static void beginCreativeGroup(std::string const&, ItemInstance const&);
  static void beginCreativeGroup(std::string const&, short, short, CompoundTag const*);
  static void buildDocumentation(DocumentationSystem&);
  static void initCreativeCategories();
  static TextureUVCoordinateSet getTextureUVCoordinateSet(std::string const&, int);

  static std::vector<ItemInstance> mCreativeList;
  static Item* mItems[4096]; //512
  static std::unordered_map<std::string, std::unique_ptr<Item>> mItemLookupMap;
  static Item* mCreativeGroups;
  static void* mCreativeGroupInfo;
  static void* mInvalidTextureUVCoordinateSet;
  static void* ICON_DESCRIPTION_PREFIX;
  static void* mInCreativeGroup;
  static void* mItemTextureAtlas;

  static Item* mSlimeBall;
  static Item* mCarrot;
  static Item* mSnowBall;
  static Item* mFilledMap;
  static Item* mBoots_iron;
  static Item* mFishingRod;
  static Item* mHelmet_iron;
  static Item* mLeggings_iron;
  static Item* mChestplate_iron;
  static Item* mBow;
  static Item* mSign;
  static Item* mSkull;
  static Item* mEnderpearl;
  static Item* mSplash_potion;
  static Item* mLingering_potion;
  static Item* mExperiencePotionItem;
  static Item* mEgg;
  static Item* mEnderEye;
  static Item* mEmerald;
  static Item* mCarrotOnAStick;
  static Item* mClock;
  static Item* mBanner;
  static Item* mCompass;
  static Item* mTotem;
  static Item* mGlass_bottle;
  static Item* mHoe_stone;
  static Item* mItemFrame;
  static Item* mMobPlacer;
  static Item* mRecordCat;
  static Item* mRecordFar;
  static Item* mFireCharge;
  static Item* mRecordMall;
  static Item* mRecordStal;
  static Item* mRecordWait;
  static Item* mRecordWard;
  static Item* mSword_gold;
  static Item* mSword_iron;
  static Item* mSword_wood;
  static Item* mHoe_diamond;
  static Item* mRecordChirp;
  static Item* mRecordStrad;
  static Item* mShovel_gold;
  static Item* mShovel_iron;
  static Item* mShovel_wood;
  static Item* mSword_stone;
  static Item* mRecordBlocks;
  static Item* mShovel_stone;
  static Item* mFlintAndSteel;
  static Item* mRecordMellohi;
  static Item* mSword_diamond;
  static Item* mWritable_book;
  static Item* mShovel_diamond;
  static Item* mBed;
  static Item* mReeds;
  static Item* mBucket;
  static Item* mPotion;
  static Item* mString;
  static Item* mEmptyMap;
  static Item* mHoe_gold;
  static Item* mHoe_iron;
  static Item* mHoe_wood;
  static Item* mPainting;
  static Item* mRecord11;
  static Item* mRecord13;
  static Item* mRedStone;
  static Item* mArrow;
  static Item* mDiamond;
  static Item* mArmorStand;
  static Item* mEndCrystal;
  static Item* mTNTMinecart;
  static Item* mChestMinecart;
  static Item* mHopperMinecart;
  static Item* mCommandBlockMinecart;
  static Item* mBoat;
  static Item* mMinecart;
  static Item* mDye_powder;
  static Item* mPaper;
  static Item* mGoldIngot;
  static Item* mIronIngot;
  static Item* mBeef_cooked;
  static Item* mGold_nugget;
  static Item* mIron_nugget;
  static Item* mNetherbrick;
  static Item* mPotatoBaked;
  static Item* mNetherQuartz;
  static Item* mRabbitCooked;
  static Item* mMutton_cooked;
  static Item* mChicken_cooked;
  static Item* mFish_cooked_cod;
  static Item* mFish_cooked_salmon;
  static Item* mCoal;
  static Item* mBrick;
  static Item* mLead;
  static Item* mBread;
  static Item* mWheat;
  static Item* mPotato;
  static Item* mGoldHorseArmor;
  static Item* mIronHorseArmor;
  static Item* mDiamondHorseArmor;
  static Item* mLeatherHorseArmor;
  static Item* mSaddle;
  static Item* mHopper;
  static Item* mEnchanted_book;
  static Item* mHelmet_leather;
  static Item* mSeeds_wheat;
  static Item* mSeeds_beetroot;
  static Item* mBeetroot;
  static Item* mRotten_flesh;
  static Item* mGenerateDenyParticleEffect;
  static Item* mGhast_tear;
  static Item* mRabbitFoot;
  static Item* mSpider_eye;
  static Item* mYellowDust;
  static Item* mBlazePowder;
  static Item* mMagma_cream;
  static Item* mNether_wart;
  static Item* mGoldenCarrot;
  static Item* mDragon_breath;
  static Item* mSpeckled_melon;
  static Item* mFish_raw_pufferfish;
  static Item* mFermented_spider_eye;
  static Item* mSugar;
  static Item* mSulphur;
  static Item* mBoots_gold;
  static Item* mBoots_chain;
  static Item* mHelmet_gold;
  static Item* mHelmet_chain;
  static Item* mBoots_diamond;
  static Item* mBoots_leather;
  static Item* mLeggings_gold;
  static Item* mHelmet_diamond;
  static Item* mLeggings_chain;
  static Item* mChestplate_gold;
  static Item* mChestplate_chain;
  static Item* mLeggings_diamond;
  static Item* mLeggings_leather;
  static Item* mChestplate_diamond;
  static Item* mChestplate_leather;
  static Item* mElytra;
  static Item* mLeather;
  static Item* mStick;
  static Item* mWritten_book;
  static Item* mFireworksItem;
  static Item* mFireworkCharge;
  static Item* mFeather;
  static Item* mRabbitRaw;
  static Item* mMutton_raw;
  static Item* mChicken_raw;
  static Item* mChorusFruit;
  static Item* mFish_raw_cod;
  static Item* mHatchet_gold;
  static Item* mHatchet_iron;
  static Item* mPickAxe_gold;
  static Item* mPickAxe_iron;
  static Item* mPorkChop_raw;
  static Item* mFish_raw_salmon;
  static Item* mPorkChop_cooked;
  static Item* mChorusFruitPopped;
  static Item* mClay;
  static Item* mBeef_raw;
  static Item* mDoor_iron;
  static Item* mDoor_wood;
  static Item* mFlowerPot;
  static Item* mApple_gold;
  static Item* mComparator;
  static Item* mDoor_birch;
  static Item* mMelonSlice;
  static Item* mRabbitHide;
  static Item* mRabbitStew;
  static Item* mDoor_acacia;
  static Item* mDoor_jungle;
  static Item* mDoor_spruce;
  static Item* mDoor_darkoak;
  static Item* mBrewing_stand;
  static Item* mApple_enchanted;
  static Item* mPrismarineShard;
  static Item* mPrismarineCrystals;
  static Item* mBook;
  static Item* mBowl;
  static Item* mCake;
  static Item* mApple;
  static Item* mFlint;
  static Item* mBlazeRod;
  static Item* mCauldron;
  static Item* mRepeater;
  static Item* mNetherStar;
  static Item* mShulkerShell;
  static Item* mHatchet_wood;
  static Item* mPickAxe_wood;
  static Item* mHatchet_stone;
  static Item* mPickAxe_stone;
  static Item* mHatchet_diamond;
  static Item* mPickAxe_diamond;
  static Item* mShears;
  static Item* mChalkboard;
  static Item* mPumpkinPie;
  static Item* mSeeds_melon;
  static Item* mBeetrootSoup;
  static Item* mMushroomStew;
  static Item* mPortfolioBook;
  static Item* mSeeds_pumpkin;
  static Item* mPoisonous_potato;
  static Item* mFish_raw_clownfish;
  static Item* mBone;
  static Item* mCamera;
  static Item* mCookie;
  static Item* mNameTag;
};