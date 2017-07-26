#include "items.h"

#include "minecraftpe/item/Item.h"

void Items::registerCustomItems()
{
    Item::mItems[470] = new Item("normal_item",470-256);
}

void Items::initItems()
{
    Items::registerCustomItems();
    Item::mItems[470]->setIcon("apple",0);
    Item::mItems[470]->setIsGlint(true);
    Item::mItems[470]->setCategory(CreativeItemCategory::TOOLS);
}

void Items::initCreativeItems()
{
    Items::registerCustomItems();
    Item::addCreativeItem(470,0);
}