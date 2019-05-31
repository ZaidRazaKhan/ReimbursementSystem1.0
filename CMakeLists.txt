cmake_minimum_required(VERSION 3.10)
project(ReimbursementSystem1_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(ReimbursementSystem1_0 main.cpp User.cpp User.h Student.cpp Student.h Professor.cpp Professor.h Staff.cpp Staff.h TripDetails.cpp TripDetails.h Credentials.cpp Credentials.h AuthenticationManager.cpp AuthenticationManager.h NotificationManager.cpp NotificationManager.h Notification.cpp Notification.h RegistrationManager.cpp RegistrationManager.h ReimbursementDetails.cpp ReimbursementDetails.h DataBaseAccessLayer.cpp DataBaseAccessLayer.h Application.cpp Application.h SimpleLogger.cpp SimpleLogger.h SignUpManually.cpp SignUpManually.h LoginManager.cpp LoginManager.h)