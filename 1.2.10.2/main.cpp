#include <jni.h>
#include <dlfcn.h>
#include <string>
#include <sstream>
#include <android/log.h>
#include "substrate.h"

#include "minecraftpe/item/Item.h"

#include "mod/sword_item.h"

void (*_Item_registerItems)(Item *);
void Item_registerItems(Item * self) {
  _Item_registerItems(self);
  Item::mItems[1000] = new Item("TestItem",1000 - 256);
  //Item::mItemLookupMap.emplace("testitem",std::unique_ptr<Item>(Item::mItems[1000]));
  Item::mItems[1000] -> setIsGlint(true);
  Item::mItems[1000] -> setCategory(CreativeItemCategory::ITEMS);

  Item::mItems[1001] = new SwordItem("SwordItem",1001 - 256);
}

void (*_Item_initClientData)(Item *);
void Item_initClientData(Item * self) {
  _Item_initClientData(self);
  Item::mItems[1000] -> setIcon("apple",0);
  Item::mItems[1001] -> setIcon("sword",0);
}

void (*_Item_initCreativeItems)(Item *);
void Item_initCreativeItems(Item * self) {
  _Item_initCreativeItems(self);
  Item::addCreativeItem(1000,0);
  Item::addCreativeItem(1001,0);
} 

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
  MSHookFunction((void*)&Item::registerItems,(void*)&Item_registerItems,(void**)&_Item_registerItems);
  MSHookFunction((void*)&Item::initClientData,(void*)&Item_initClientData,(void**)&_Item_initClientData);
  MSHookFunction((void*)&Item::initCreativeItems,(void*)&Item_initCreativeItems,(void**)&_Item_initCreativeItems);
  return JNI_VERSION_1_2;
}