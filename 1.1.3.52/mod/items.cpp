#include "items.h"

#include "minecraftpe/item/Item.h"

#include "items/sword_item.h"

void Items::registerCustomItems()
{
    Item::mItems[470] = new Item("normal_item",470-256);
    Item::mItems[471] = new SwordItem("sword_item",471-256);
}

void Items::initItems()
{
    Items::registerCustomItems();
    Item::mItems[470]->setIcon("apple",0);
    Item::mItems[470]->setIsGlint(true);
    Item::mItems[470]->setCategory(CreativeItemCategory::TOOLS);
    //Item::mItems[471]->setIcon("sword",0);
}

void Items::initCreativeItems()
{
    Items::registerCustomItems();
    Item::addCreativeItem(470,0);
    Item::addCreativeItem(471,0);
}