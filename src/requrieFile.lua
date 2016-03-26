cc.exports.RequrieFile = {

}


function cc.exports.RequrieFile.load()
    
    require "loadData"
    require "ui_loading"
    require "ui_util"
    require "constants"
    require "cppToLua"
    require "ziYaHall"
    require "ui_mainCityLayer"
    require "storeLayer"
    require "heroList"
    require "treasureLayer"


end
function cc.exports.RequrieFile.show()
    LoadData.load()
    
end

