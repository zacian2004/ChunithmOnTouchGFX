Rhythm Game Project
Mô tả
Trò chơi âm nhạc (rhythm game) được phát triển trên bo mạch STM32F429I-DISCO với màn hình cảm ứng ILI9341, sử dụng framework TouchGFX 4.25.0. Người chơi nhấn vào 4 lane cảm ứng để ghi điểm dựa trên thời điểm nốt nhạc đến judge line, nhận phản hồi Perfect/Good/Miss, và xem kết quả cuối cùng.
Yêu cầu cài đặt
Phần cứng:
Bo mạch STM32F429I-DISCO (hoặc tương thích).
Màn hình ILI9341 (240x320, RGB565).
Cảm biến cảm ứng STMPE811.
Phần mềm:
TouchGFX Designer 4.25.0.
STM32CubeIDE 1.15.0.
Compiler: GCC hoặc ARMCC.
FreeRTOS CMSIS V2.
Hướng dẫn cài đặt
Cài đặt TouchGFX Designer và mở project từ mã nguồn.
Cấu hình STM32CubeIDE với thư viện TouchGFX và FreeRTOS.
Kết nối bo mạch STM32F429I-DISCO qua ST-LINK.
Biên dịch và nạp mã lên bo mạch.
Chạy ứng dụng và kiểm tra trên màn hình cảm ứng.
Version công cụ
TouchGFX: 4.25.0
STM32CubeIDE: 1.15.0
FreeRTOS: CMSIS V2
Compiler: GCC hoặc ARMCC
 
