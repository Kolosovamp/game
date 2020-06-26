#include "gameboard.h"

GameBoard::GameBoard(const size_t maxWidth, const size_t maxHeight)  :
    maxWidth(maxWidth), maxHeight(maxHeight), currentUnitCount(0), currentBaseCount(0), maxBaseCount(maxWidth*maxHeight/4), maxUnitCount(maxWidth*maxHeight-maxBaseCount){

    this->unitManager = new UnitManager;
    field = new BoardComponent** [maxHeight];
    landscapeMap.clear();

    for (size_t i = 0; i < maxHeight; i++) {
        field[i] = new BoardComponent* [maxWidth];
        for (size_t j = 0; j < maxWidth; j++) {

            field[i][j] = new BoardComponent;
            field[i][j]->setManager(unitManager);
            std::pair<size_t, size_t> el;
            el.first = i;
            el.second = j;
            switch (rand() % 3 + 1) {
                case 1:
                    field[i][j]->setLandscape(new ProxyLandscape(MOUNTAIN));
                    landscapeMap[MOUNTAIN].push_back(el);
                    break;
                case 2:
                    field[i][j]->setLandscape(new ProxyLandscape(FOREST));
                    landscapeMap[FOREST].push_back(el);
                    break;
                case 3:
                    field[i][j]->setLandscape(new ProxyLandscape(PLAIN));
                    landscapeMap[PLAIN].push_back(el);
                    break;
            }

        }
    }

}


GameBoard::GameBoard(const GameBoard &board) :
    maxWidth(board.maxWidth), maxHeight(board.maxHeight), currentUnitCount(board.currentUnitCount), currentBaseCount(board.currentBaseCount), maxBaseCount(board.maxBaseCount),
    maxUnitCount(board.maxUnitCount), unitManager(board.unitManager) {
    //конструктор копирования
    std::cout<<"copy board"<<std::endl;
    for(size_t i = 0; i < maxHeight; i++){
        field[i] = new BoardComponent*[maxWidth];
        for(size_t j = 0; j < maxWidth; j++){
            field[i][j] = board.field[i][j];
        }
    }
}

GameBoard::GameBoard(GameBoard &&board) :
    maxWidth(board.maxWidth), maxHeight(board.maxHeight), currentUnitCount(board.currentUnitCount), currentBaseCount(board.currentBaseCount), maxBaseCount(board.maxBaseCount),
    maxUnitCount(board.maxUnitCount), unitManager(board.unitManager) {
    //конструктор перемещения
    for(size_t i = 0; i < maxHeight; i++){
        field[i] = new BoardComponent*[maxWidth];
        for(size_t j = 0; j < maxWidth; j++){
            field[i][j] = board.field[i][j];
        }
    }
}

GameBoard::~GameBoard(){

    for(size_t i = 0; i < maxHeight; i++){
        for(size_t j = 0; j < maxWidth; j++){
            field[i][j] = nullptr;
        }
        field[i] = nullptr;
    }
    field = nullptr;
    unitManager = nullptr;

}

bool GameBoard::setUnit(IUnit *newUnit) {

    size_t x = newUnit->getCoord().x;
    size_t y = newUnit->getCoord().y;

    std::cout<<newUnit->ID<<std::endl;

    if(x < this->maxWidth && y < this->maxHeight && this->currentUnitCount < this->maxUnitCount){//>0
        if((this->field)[x][y]->setUnit(newUnit)){//удачная установка
            if(newUnit->ID == 0)//объект новый или перемещаемый
                newUnit->ID = this->currentUnitCount + 1;
            this->currentUnitCount ++;
            //unitManager->notifyObservers(CREATE);
            return true;
        }
    }
    return false;
}

bool GameBoard:: moveUnit(IUnit *unit, size_t newX, size_t newY){

    if(!unit)
        return false;
    //current coords
    size_t x = unit->getCoord().x;
    size_t y = unit->getCoord().y;

    if(x < maxWidth && y < maxHeight){
        if(!(this->field)[x][y]->deleteUnit()){
            return false;
        }
    }
    //return false;
    unit->changeCoord(newX, newY);//смена координат

    //this->currentUnitCount --;

    std::cout<<"MOVE"<<std::endl;
    if (this->setUnit(unit)){
        return true;
    }
    return false;
}

bool GameBoard::setBase(Base *newBase){

    size_t x = newBase->getCoord().x;
    size_t y = newBase->getCoord().y;

    if(x < this->maxWidth && y < this->maxHeight && this->currentBaseCount < this->maxBaseCount){
        if((this->field)[x][y]->setBase(newBase)){            
            this->currentBaseCount ++;
            /*this->unitManager->subscribeObserverForUpdates(CREATE, newBase);
            this->unitManager->subscribeObserverForUpdates(DESTROY, newBase);*/
            return true;
        }
    }
    return false;
}

void GameBoard::printField() const{

    for(size_t i = 0; i < this->maxHeight; i++){
        for(size_t j = 0; j < this->maxWidth; j++){
            if((this->field)[i][j]->empty())
                std::cout<<"o";
            else std::cout<<"x";
        }
        std::cout<<"\n";
    }

}

size_t GameBoard::getMaxWidth() const{
    return this->maxWidth;
}

size_t GameBoard::getMaxHeight() const{
    return  this->maxHeight;
}

BoardComponent*** GameBoard::getField() const{
    return this->field;
}

BoardIterator::BoardIterator(GameBoard* fieldAttachedTo)
{
    this->board = fieldAttachedTo;
    currentWidth = 0;
    currentHeight = 0;
    maxWidth = board->getMaxWidth();
    maxHeight = board->getMaxHeight();
}

void BoardIterator::reset() {
    currentWidth = 0;
    currentHeight = 0;
}

bool BoardIterator::hasNext() {
    if(currentWidth < maxWidth && currentHeight < maxHeight)
        return true;
    else return false;
}

BoardComponent* BoardIterator::getNext()
{
    BoardComponent* cell = board->getField()[currentWidth][currentHeight];
    currentWidth++;
    if(currentWidth == maxWidth - 1)
    {
        currentWidth = 0;
        currentHeight++;
    }
    return cell;
}

bool GameBoard::deleteUnit(IUnit* unit){

    size_t x = unit->getCoord().x;
    size_t y = unit->getCoord().y;    

    if(x < maxWidth && y < maxHeight){
        unit->ID = 0;
        if((this->field)[x][y]->deleteUnit()){
            return true;
        }
    }
    return false;

}


bool GameBoard::deleteBase(Base* base){

    size_t x = base->getCoord().x;
    size_t y = base->getCoord().y;

    if(x < maxWidth && y < maxHeight){
        if((this->field)[x][y]->deleteBase()){
            this->currentBaseCount --;
            return true;
        }
    }
    return false;
}
