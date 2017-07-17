#include "items.h"

#include "minecraftpe/item/Item.h"

void Items::registerCustomItems()
{
    Item::mItems[511] = new Item("TestItem",511-256);
}

void Items::initItems()
{
    Items::registerCustomItems();
    Item::mItems[511]->setIcon("apple",0);
    Item::mItems[511]->setIsGlint(true);
    Item::mItems[511]->setCategory(CreativeItemCategory::TOOLS);
}

void Items::initCreativeItems()
{
    Items::registerCustomItems();
    Item::addCreativeItem(511,0);
}