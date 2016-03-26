cc.exports.StoreLayer = {
	mStoreLayer = nill,
	StoreLayer_layer = nill,
}

function StoreLayer.load()
	StoreLayer.mStoreLayer = cc.Layer:create()
	StoreLayer.StoreLayer_layer = cc.CSLoader:createNode("UI/allcsd/StroeLayer.csb")
	StoreLayer.StoreLayer_layer:setTag(1)
	StoreLayer.mStoreLayer:retain()
	StoreLayer.mStoreLayer:addChild(StoreLayer.StoreLayer_layer)
	return StoreLayer.mStoreLayer
end
function StoreLayer.show()
	Util.addCurrentScene(StoreLayer.mStoreLayer)
    Util.layerToOther(StoreLayer.mStoreLayer)

	Util.hide(StoreLayer.mStoreLayer)	 
	StoreLayer.showDetail()
end

function StoreLayer.showDetail()
	local wuJin = StoreLayer.StoreLayer_layer:getChildByName("WuJin")
	local lingQi = StoreLayer.StoreLayer_layer:getChildByName("LingQi")
	

    wuJin:loadTextures("UI/store/55.png","UI/store/56.png","")
    lingQi:loadTextures("UI/store/56.png","UI/store/55.png","")
  

    wuJin:setTitleColor(cc.c3b(255,255, 255))
    lingQi:setTitleColor(cc.c3b(191,191, 191))

	-- skillPanel:setVisible(false)
 --    propertyPanel:setVisible(false)
    
    
	local function showRoleMsg(ref,touchType)
		local butName = ref:getName()
		 if touchType==ccui.TouchEventType.began then
            --Util.touchButton()

        elseif touchType == ccui.TouchEventType.ended then 
        	if "WuJin" == butName then
                wuJin:loadTextures("UI/store/55.png","UI/store/56.png","")  
        		lingQi:loadTextures("UI/store/56.png","UI/store/55.png","")
               
               
                wuJin:setTitleColor(cc.c3b(255,255, 255))
                lingQi:setTitleColor(cc.c3b(191,191, 191))
                

        		-- equPanel:setVisible(true)
        		-- skillPanel:setVisible(false)
          --       propertyPanel:setVisible(false)

        	elseif "LingQi" == butName then 
        		wuJin:loadTextures("UI/store/56.png","UI/store/55.png","")  
                lingQi:loadTextures("UI/store/55.png","UI/store/56.png","")
                

                wuJin:setTitleColor(cc.c3b(191,191, 191))
                lingQi:setTitleColor(cc.c3b(255,255, 255))
                

                --equPanel:setVisible(false)
                --skillPanel:setVisible(true)
                
        	end
        
        elseif touchType == ccui.TouchEventType.canceled then

        end
	end


   	wuJin:addTouchEventListener(showRoleMsg)
   	lingQi:addTouchEventListener(showRoleMsg)
    



end