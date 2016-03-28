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
    Util.layerToOther(HeroList.mHeroListLayer)

	local function toBattleCallBack(ref,touchType)
		local butName=ref:getName()
        if touchType==ccui.TouchEventType.began then
	       
        	
        elseif touchType == ccui.TouchEventType.ended then 
        	if  "Button_14" == butName then 
	    		       		
    		else
	    		
           end
           -- effect
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end
	Util.hide(HeroList.mHeroListLayer)
end