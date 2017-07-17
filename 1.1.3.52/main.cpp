#include <jni.h>
#include <dlfcn.h>
#include <string>
#include <sstream>
#include <android/log.h>
#include "substrate.h"

#include "minecraftpe/item/Item.h"

#include "mod/items.h"

void (*_Item_initClientData)(Item *);
void Item_initClientData(Item * self)
{
    _Item_initClientData(self);
    Items::initItems();
}

void (*_Item_initCreativeItems)(Item *);
void Item_initCreativeItems(Item * self)
{
    _Item_initCreativeItems(self);
    Items::initCreativeItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    MSHookFunction((void*)&Item::initClientData,(void*)&Item_initClientData,(void**)&_Item_initClientData);
    MSHookFunction((void*)&Item::initCreativeItems,(void*)&Item_initCreativeItems,(void**)&_Item_initCreativeItems);
    return JNI_VERSION_1_2;
}