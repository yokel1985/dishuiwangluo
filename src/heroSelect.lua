cc.exports.HeroSelect = {
	mHeroSelectLayer = nill,
	HeroSelect_layer = nill,
}

function HeroSelect.load()
	HeroSelect.mHeroSelectLayer = cc.Layer:create()
	HeroSelect.HeroSelect_layer = cc.CSLoader:createNode("UI/allcsd/SelectHeroLayer.csb")
	HeroSelect.HeroSelect_layer:setTag(1)
	--HeroSelect.mHeroSelectLayer:retain()
	HeroSelect.HeroSelect_layer:setScale(0.1)

	HeroSelect.HeroSelect_layer:setAnchorPoint(cc.p(0.5,0.5))
	HeroSelect.mHeroSelectLayer:setPosition(Constants.WIDTH/2,Constants.HEIGHT/2)
	HeroSelect.mHeroSelectLayer:addChild(HeroSelect.HeroSelect_layer)
	return HeroSelect.mHeroSelectLayer
end
function HeroSelect.show()
	Util.addCurrentScene(HeroSelect.mHeroSelectLayer)
    Util.layerToOther(HeroSelect.HeroSelect_layer )
    local action = cc.ScaleTo:create(0.5,1.2)
    HeroSelect.HeroSelect_layer:runAction(action)

    local  btns = {}
	local function toBattleCallBack(ref,touchType)
		local butName=ref:getName()
        if touchType==ccui.TouchEventType.began then
	       
        	
        elseif touchType == ccui.TouchEventType.ended then 
        	print(" lua  to c++ secene ")
            cpp_tobattleScene()
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end

	local root = HeroSelect.HeroSelect_layer:getChildByName("Panel_1")
	local btnPanel = ccui.Helper:seekWidgetByName(root, "ScrollView_1")
	for i=1,5 do
		btns[i] = ccui.Helper:seekWidgetByName(btnPanel, "Button_2_"..(i-1))
		btns[i]:addTouchEventListener(toBattleCallBack)

	end
	Util.hide(HeroSelect.mHeroSelectLayer)
end