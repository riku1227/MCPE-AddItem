#pragma once

#include <minecraftpe/world/item/Item.h>

class ResourcePackManager;

class Documentation {
public:
    class Writer;
};

class ItemRegistry {
public:
  static void initClientData();
  static Item* getItem(short);
  static int getItemCount();
  static void lookupByName(std::string const&, bool);
  static Item* allItems();
  static void registerItem(std::unique_ptr<Item>&&);
  static void teardownAll();
  static void registerAlias(std::string const&, std::string const&);
  static void initServerData(ResourcePackManager&);
  static void unregisterItem(std::string const&);
  static void startRegistration();
  static void buildDocumentation(Documentation::Writer&);
  static void finishedRegistration();
  static Item* getItem(std::string const&);
  static void _setItem(short, Item const*);

  static void* mItemRegistry;
  static void* mItemLookupMap;
  static void* mItemAliasLookupMap;
  static void* mItems;
};
