cc.exports.HeroList = {
	mHeroListLayer = nill,
	HeroList_layer = nill,
}

function HeroList.load()
	HeroList.mHeroListLayer = cc.Layer:create()
	HeroList.HeroList_layer = cc.CSLoader:createNode("UI/allcsd/HeroLayer.csb")
	HeroList.HeroList_layer:setTag(1)
	HeroList.mHeroListLayer:retain()
	HeroList.mHeroListLayer:addChild(HeroList.HeroList_layer)
	return HeroList.mHeroListLayer
end
function HeroList.show()
	Util.addCurrentScene(HeroList.mHeroListLayer)
    Util.layerToOther(HeroList.HeroList_layer)
    local heroBtns = {}
	local function showHeroCallBack(ref,touchType)
		local btnTag=ref:getTag()
        if touchType==ccui.TouchEventType.began then
        	
        elseif touchType == ccui.TouchEventType.ended then 

        	for i=1,9 do
        		if btnTag == i then
					heroBtns[i]:loadTextures("UI/hero/43.png","UI/hero/44.png","")
        		else
					heroBtns[i]:loadTextures("UI/hero/44.png","UI/hero/44.png","")

        		end
        	end
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end

	local root = HeroList.HeroList_layer:getChildByName("Panel_1")
	local btnPanel = ccui.Helper:seekWidgetByName(root, "ScrollView_1")
	for i=1,9 do
		heroBtns[i] = ccui.Helper:seekWidgetByName(btnPanel, "Button_5_"..(i-1))
		heroBtns[i]:setTag(i)
		heroBtns[i]:loadTextures("UI/hero/44.png","UI/hero/44.png","")
		if 1 == i then
			heroBtns[i]:loadTextures("UI/hero/43.png","UI/hero/44.png","")
			
		end
		heroBtns[i]:addTouchEventListener(showHeroCallBack)
	end

	Util.hide(HeroList.mHeroListLayer)
end