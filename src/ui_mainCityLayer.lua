
-- 主界面  利用滑动显示或消失界面的按钮 
cc.exports.MainCity={
    mMainLayer=nil,
	main_lay=nil,
	panelRoot1=nil,
	panelRoot2=nil,
	proPosition=nil,
	downBut=nil,
	isTouch=true,
	rightButton=nil,
	rightTouch=true,
	
}

function MainCity.load()
	MainCity.mMainLayer = cc.Layer:create()
 	MainCity.main_lay = cc.CSLoader:createNode("UI/allcsd/MainLayer.csb")
	MainCity.main_lay:setOpacity(0)
	MainCity.mMainLayer:retain()
	MainCity.mMainLayer:addChild(MainCity.main_lay)
	MainCity.main_lay:setTag(1)
	return MainCity.mMainLayer
end
	
function MainCity.show()
	Util.addCurrentScene(MainCity.mMainLayer)
    Util.layerToOther(MainCity.main_lay )
    
    local function touchMainBut(ref,touchType)
		local butName=ref:getName()
        if touchType==ccui.TouchEventType.began then

        elseif touchType == ccui.TouchEventType.ended then 
	       
	        if "Button_3" == butName then
	        	StoreLayer.load()
    			StoreLayer.show()
	        elseif "Button_3_0" == butName then
	        	ZiYaHall.load()
	        	ZiYaHall.show()	        	
	        elseif "Button_3_1" == butName then
	        	HeroList.load()
	        	HeroList.show()
        	elseif "Button_3_2" == butName then
	        	HeroSelect.load()
	        	HeroSelect.show()
	        end
	        
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end	
	local storeBtn = MainCity.main_lay:getChildByName("Button_3")
		storeBtn:addTouchEventListener(touchMainBut)
	local ziYaHall = MainCity.main_lay:getChildByName("Button_3_0")
		ziYaHall:addTouchEventListener(touchMainBut)
	local heroBtn = MainCity.main_lay:getChildByName("Button_3_1")
		heroBtn:addTouchEventListener(touchMainBut)
	local battleBtn = MainCity.main_lay:getChildByName("Button_3_2")
		battleBtn:addTouchEventListener(touchMainBut)
		
end

function MainCity.hide()
	if MainCity.mMainLayer:getParent() then
		MainCity.mMainLayer:getParent():removeChild(MainCity.mMainLayer, true)
	end
end
