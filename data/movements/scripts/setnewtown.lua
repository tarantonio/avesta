function onStepIn(cid, item, topos, frompos)
    if item.actionid == 8701 then
        doPlayerSendTextMessage(cid, 22, "You are now citizen of Edron!")
        doPlayerSetTown(cid, 1)
        return TRUE
    end

    if item.actionid == 8702 then
        doPlayerSendTextMessage(cid, 22, "You are now citizen of Carlin!")
        doPlayerSetTown(cid, 2)
        return TRUE
    end
end