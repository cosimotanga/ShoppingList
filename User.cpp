#include "User.h"

User::User(const std::string& id) : id(id) {}

User::~User() {
    // Finché ci sono liste nella lista di liste dell'utente...
    while (!lists.empty()) {
        // Rimuovi l'utente da quella lista e elimina la lista dalla lista di liste dell'utente
        lists.back()->detach(this);
        lists.pop_back();
    }
}

void User::update(const std::string listName) {
    for (size_t i = 0; i < lists.size(); ++i) {
        if (lists[i]->getListName() == listName) {
            std::cout << "La lista" << listName << " è stata aggiornata per l'uente " << id << " :" << std::endl;
            showList(lists[i]);
            return;
        }
    }
}

void User::showList(const ShoppingList* list) const {
    // Otteniamo il numero di prodotti non venduti nella lista
    int remainingProducts = list->getUnsoldProductQuantity();
    std::cout << "Elementi dalla lista " << list->getListName() << " mancanti da comprare: " << remainingProducts << std::endl;

    // Otteniamo tutti i prodotti dalla lista
    const std::vector<Product>& products = list->getProducts();

    // Iteriamo attraverso tutti i prodotti nella lista utilizzando un ciclo range-based
    for (const Product& product : products) {
        // Stampiamo le informazioni del prodotto corrente
        std::cout << product.getName() << " - Quantità: " << product.getQuantity();
        
        // Verifichiamo se il prodotto è stato venduto e stampiamo di conseguenza
        if (product.isSold())
            std::cout << " x ";
        
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void User::addProduct(ShoppingList* list,const Product& p) {
    list->addProduct(p);
    std::cout << "Elemento aggiunto alla lista della spesa " << list->getListName()<< " "<< std::endl;
}

void User::removeProduct(ShoppingList* list, int position) {
    list->removeProduct(position);
    std::cout << "Elemento rimosso dalla lista della spesa" << std::endl;
} 

void User::addList(ShoppingList* list) {
    lists.push_back(list);
    list->attach(this);
}

void User::removeList(ShoppingList* targetList) {
    // Rimuove la lista dalla lista delle liste della spesa dell'utente
    for(int i = 0; i < lists.size(); i++){
        if(lists[i] == targetList)
            lists.erase(std::next(lists.begin(),i));
    }

    // Stacca l'utente dalla lista della spesa
    targetList->detach(this);


}

void User::getAllShoppingLists() {
    std::cout << "Liste per utente " << this->getUserId() << " - Numero totale: " << this->getListsNumber() << std::endl;
    
    for (const auto& list : lists) {
        std::cout << "  - Nome lista: " << list->getListName() << ", Prodotti mancanti: " << list->getUnsoldProductQuantity() << std::endl;
    }
}

void User::purchasedProducts(ShoppingList* lista, int index) {
    std::cout << "Elemento acquistato: " << std::endl;
    lista->productPurchased(index);
}
