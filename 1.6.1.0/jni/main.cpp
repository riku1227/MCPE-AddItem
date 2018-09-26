#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "minecraftpe/world/item/VanillaItems.h"
#include "minecraftpe/world/item/Item.h"
#include "minecraftpe/world/registry/ItemRegistry.h"

Item* VanillaItems::mTestItem = nullptr;

void (*_VanillaItems_registerItems)(VanillaItems*,bool);
void VanillaItems_registerItems(VanillaItems* vanillaItems, bool _bool) {
  _VanillaItems_registerItems(vanillaItems, _bool);
  VanillaItems::mTestItem = new Item("test_item", 17000);
  VanillaItems::mTestItem -> setIcon("apple", 0);
  VanillaItems::mTestItem -> setCategory(CreativeItemCategory::ITEMS);
  VanillaItems::mTestItem -> setMaxStackSize(27);
  ItemRegistry::registerItem(std::unique_ptr<Item> (VanillaItems::mTestItem));
}

void (*_VanillaItems_initClientData)(VanillaItems*);
void VanillaItems_initClientData(VanillaItems* vanillaItems) {
  _VanillaItems_initClientData(vanillaItems);
  
  VanillaItems::mTestItem -> setIcon("apple", 0);
}

void (*_Item_initCreativeItems)(bool, void*);
void Item_initCreativeItems(bool b1, void* func) {
  _Item_initCreativeItems(b1, func);

  Item::addCreativeItem(VanillaItems::mTestItem, 0);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  MSHookFunction((void*)&VanillaItems::registerItems,(void*)&VanillaItems_registerItems,(void**) &_VanillaItems_registerItems);
  MSHookFunction((void*)&VanillaItems::initClientData,(void*)&VanillaItems_initClientData,(void**) &_VanillaItems_initClientData);
  MSHookFunction((void*)&Item::initCreativeItems,(void*)&Item_initCreativeItems,(void**) &_Item_initCreativeItems);
  return JNI_VERSION_1_2;
}