#include "landscapes.h"

void ProxyLandscape::influenceOnUnit() {
    if(realLandscape == nullptr){
        switch (type) {
            case MOUNTAIN:
                realLandscape = new Mountain;
                break;
            case FOREST:
                realLandscape = new Forest;
                break;
            case PLAIN:
                realLandscape = new Plain;
                break;

        }
    }
    if(realLandscape)
        realLandscape->influenceOnUnit();
}
