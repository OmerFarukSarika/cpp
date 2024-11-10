#include <iostream>
#include <thread>  // std::this_thread::sleep_for
#include <chrono>  // std::chrono::seconds

void processFile(int steps) {
    for (int i = 1; i <= steps; ++i) {
        // İlerleme çubuğunu yazdır
        std::cout << "İşlem: " << i << "/" << steps << " adım tamamlandı.";
        
        // std::flush kullanarak tamponu hemen boşalt ve ekrana yazdır
        std::cout << std::flush;
        
        // İşlem tamamlanmadan önce birkaç saniye bekle (simülasyon)
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        // Yeni satır yazmadan ilerleme çubuğunun üzerine yazmaya devam et
        std::cout << "\r";  // Carriage return: satır başına dön
    }

    // Sonunda yeni bir satır ekle
    std::cout << "\nİşlem Tamamlandı!" << std::endl;
}

int main() {
    int totalSteps = 5;
    std::cout << "Dosya işleniyor..." << std::endl;
    
    // Dosya işlemi simülasyonu
    processFile(totalSteps);
    
    return 0;
}
