function onStepIn(cid, item, topos, frompos)
    doTransformItem(item.uid, item.itemid + 1)
    doDecayItem(item.uid)
end