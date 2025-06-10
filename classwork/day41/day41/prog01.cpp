#include <iostream>
#include <unordered_set>

int main() {
    std::unordered_set<std::string> cities;

    // Insert elements
    cities.insert("Mumbai");
    cities.insert("Delhi");
    cities.insert("Chennai");
    cities.insert("Kolkata");

    // Emplace (in-place construction)
    cities.emplace("Hyderabad");

    // Display contents
    std::cout << "Cities in the set:\n";
    for (const auto& city : cities) {
        std::cout << city << "\n";
    }

    // Count & Find
    std::string searchCity = "Delhi";
    if (cities.count(searchCity)) {
        std::cout << "\n" << searchCity << " found in the set.\n";
    }

    // Using find()
    auto it = cities.find("Mumbai");
    if (it != cities.end()) {
        std::cout << *it << " is found. Erasing it.\n";
        cities.erase(it);

    }

    // Show size and load factor
    std::cout << "\nSet size: " << cities.size() << "\n";
    std::cout << "Bucket count: " << cities.bucket_count() << "\n";
    std::cout << "Load factor: " << cities.load_factor() << "\n";

    // Rehashing
    cities.rehash(20); // Force rehash into 20 buckets
    std::cout << "After rehash - New bucket count: " << cities.bucket_count() << "\n";


    std::cout << "\nSet size: " << cities.size() << "\n";
    std::cout << "Bucket count: " << cities.bucket_count() << "\n";
    std::cout << "Load factor: " << cities.load_factor() << "\n";

    // Clear
    cities.clear();
    std::cout << "Set cleared. Is empty? " << std::boolalpha << cities.empty() << "\n";

    return 0;
}