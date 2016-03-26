cc.exports.ZiYaHall = {
	mZiYaHallLayer = nill,
	ZiYaHall_layer = nill,
}

function ZiYaHall.load()
	ZiYaHall.mZiYaHallLayer = cc.Layer:create()
	ZiYaHall.ZiYaHall_layer = cc.CSLoader:createNode("UI/allcsd/ZiYaHallLayer.csb")
	ZiYaHall.ZiYaHall_layer:setTag(1)
	ZiYaHall.mZiYaHallLayer:retain()
	ZiYaHall.mZiYaHallLayer:addChild(ZiYaHall.ZiYaHall_layer)
	return ZiYaHall.mZiYaHallLayer
end
function ZiYaHall.show()
	Util.addCurrentScene(ZiYaHall.mZiYaHallLayer)
    Util.layerToOther(ZiYaHall.mZiYaHallLayer )

	local function toMainCallBack(ref,touchType)
		local butName=ref:getName()
        if touchType==ccui.TouchEventType.began then
	        Util.touchButton()
        	
        elseif touchType == ccui.TouchEventType.ended then 
        	TreasureLayer.load()
        	TreasureLayer.show()
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end

	Util.hide(ZiYaHall.mZiYaHallLayer)	 
	
	local buyBtn1 = ZiYaHall.ZiYaHall_layer:getChildByName("Button_2")
	buyBtn1:addTouchEventListener(toMainCallBack)
	local buyBtn2 = ZiYaHall.ZiYaHall_layer:getChildByName("Button_2_0")
	buyBtn2:addTouchEventListener(toMainCallBack)
	
end