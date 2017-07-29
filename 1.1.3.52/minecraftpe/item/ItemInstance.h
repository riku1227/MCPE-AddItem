#pragma once

/*
MCPE 1.1.3.52
*/

#include <memory>

class Item;
class Block;
class CompoundTag;
class BlockEntity;
class BlockSource;
class Level;
class Entity;
class Mob;
class Player;
class BlockID;
class ItemEnchants;
class IDataInput;
class IDataOutput;

namespace Json
{
	class Value;
}

class ItemInstance
{
public:
    ItemInstance(Item const&, int);
    ItemInstance(ItemInstance const&);
    ItemInstance(Item const&);
    ItemInstance(Block const&);
    ItemInstance(int, int, int);
    ItemInstance();
    ItemInstance(Item const&, int, int);
    ItemInstance(Block const&, int);
    ItemInstance(Block const&, int, int);
    ItemInstance(Item const&, int, int, CompoundTag const*);
    ItemInstance(int, int, int, CompoundTag const*);
public:
    ~ItemInstance();
    int getUseAnimation() const;
    bool isNull() const;
    std::string getHoverName() const;
    std::string getEffectName() const;
    void setAuxValue(short);
    void operator=(ItemInstance const&);
    int getAuxValue() const;
    bool isOffhandItem() const;
    bool isWearableItem() const;
    void sameItemAndAux(ItemInstance const&) const;
    int getMaxStackSize() const;
    bool isDamageableItem() const;
    void clone() const;
    int getId() const;
    std::string getName() const;
    void add(int);
    bool isFullStack() const;
    void operator==(ItemInstance const&) const;
    void set(int);
    void addCustomUserData(BlockEntity&, BlockSource&);
    void setNull();
    bool isThrowable() const;
    bool isEquivalentArmor(ItemInstance const&) const;
    void* getStrippedNetworkItem() const;
    void operator!=(ItemInstance const&) const;
    int getMaxUseDuration() const;
    bool isHorseArmorItem() const;
    bool isArmorItem() const;
    bool isGlint() const;
    bool hasCustomHoverName() const;
    void* getIcon(int, bool) const;
    int getColor() const;
    int getMaxDamage() const;
    int getDamageValue() const;
    bool isDamaged() const;
    bool isStackedByData() const;
    bool matches(ItemInstance const&) const;
    bool isStackable() const;
    int getIdAuxEnchanted() const;
    int getIdAux() const;
    bool isLiquidClipItem() const;
    std::string getFormattedHovertext(Level&, bool) const;
    void setUserData(std::unique_ptr<CompoundTag, std::default_delete<CompoundTag> >);
    void retrieveIDFromIDAux(int);
    void retrieveAuxValFromIDAux(int);
    void retrieveEnchantFromIDAux(int);
    void* getEnchantsFromUserData() const;
    void onCraftedBy(Level&, Player&);
    void addComponents(Json::Value const&, std::string&);
    void remove(int);
    void fromTag(CompoundTag const&);
    bool isStackable(ItemInstance const&) const;
    bool matchesItem(ItemInstance const&) const;
    void save() const;
    void setCustomName(std::string const&);
    void setRepairCost(int);
    void resetHoverName();
    bool isEnchantingBook() const;
    int getBaseRepairCost() const;
    void setJustBrewed(bool);
    bool isPotionItem() const;
    bool wasJustBrewed() const;
    bool isEnchanted() const;
    void getEnchantValue() const;
    void inventoryTick(Level&, Entity&, int, bool);
    void hurtAndBreak(int, Entity*);
    void* getUserData() const;
    bool hasUserData() const;
    void load(CompoundTag const&);
    int getAttackDamage() const;
    void releaseUsing(Player*, int);
    void interactEnemy(Mob*, Player*);
    void useTimeDepleted(Level*, Player*);
    void hurtEnemy(Mob*, Mob*);
    void startCoolDown(Player*) const;
    float getDestroySpeed(Block const&) const;
    bool canDestroySpecial(Block const&) const;
    bool use(Player&);
    bool useOn(Entity&, int, int, int, signed char, float, float, float);
    void mineBlock(BlockID, int, int, int, Mob*);
    void componentsMatch(ItemInstance const&) const;
    bool hasSameUserData(ItemInstance const&) const;
    void saveEnchantsToUserData(ItemEnchants const&);
    void deserializeComponents(IDataInput&);
    std::string getCustomName() const;
    void serializeComponents(IDataOutput&) const;
    void _initComponents();
    void _loadComponents(CompoundTag const&);
    void updateComponent(std::string const&, Json::Value const&);
    void _cloneComponents(ItemInstance const&);
    bool isValidComponent(std::string const&);
    void setDescriptionId(std::string const&);
    void init(int, int, int);
    void snap(Player*);
    void _setItem(int);
    void useAsFuel();
    bool canDestroy(Block const*) const;
    bool canPlaceOn(Block const*) const;
    std::string getRawNameId() const;
    bool hasComponent(std::string const&) const;
    bool _hasComponents() const;
    int getEnchantSlot() const;
    void _saveComponents(CompoundTag&) const;
    void* getNetworkUserData() const;
    std::string _getHoverFormattingPrefix() const;
    std::string toString() const;
public:
    static ItemInstance * EMPTY_ITEM;
    static std::string const TAG_ENCHANTS;
    static std::string const TAG_DISPLAY;
    static int const MAX_STACK_SIZE;
    static std::string const TAG_CAN_DESTROY;
    static std::string const TAG_REPAIR_COST;
    static std::string const TAG_CAN_PLACE_ON;
    static std::string const TAG_DISPLAY_NAME;
    static std::string const TAG_STORE_CAN_DESTROY;
    static std::string const TAG_STORE_CAN_PLACE_ON;
    static std::string const TAG_LORE;
};