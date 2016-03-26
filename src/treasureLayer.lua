cc.exports.TreasureLayer = {
	mTreasureLayer = nill,
	TreasureLayer_layer = nill,
}

function TreasureLayer.load()
	TreasureLayer.mTreasureLayer = cc.Layer:create()
	TreasureLayer.TreasureLayer_layer = cc.CSLoader:createNode("UI/allcsd/TreasureLayer.csb")
	TreasureLayer.TreasureLayer_layer:setTag(1)
	TreasureLayer.TreasureLayer_layer:setScale(0.1)
	TreasureLayer.mTreasureLayer:retain()
	TreasureLayer.TreasureLayer_layer:setAnchorPoint(cc.p(0.5,0.5))
	TreasureLayer.mTreasureLayer:setPosition(Constants.WIDTH/2,Constants.HEIGHT/2)
	TreasureLayer.mTreasureLayer:addChild(TreasureLayer.TreasureLayer_layer)
	return TreasureLayer.mTreasureLayer
end
function TreasureLayer.show()
	Util.addCurrentScene(TreasureLayer.mTreasureLayer)
    Util.layerToOther(TreasureLayer.mTreasureLayer)
    local action = cc.ScaleTo:create(0.5,1)
    TreasureLayer.TreasureLayer_layer:runAction(action)
	local function toBattleCallBack(ref,touchType)
		local butName=ref:getName()
        if touchType==ccui.TouchEventType.began then       	
        elseif touchType == ccui.TouchEventType.ended then 
   
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end
	Util.hide(TreasureLayer.mTreasureLayer)	 
	
end