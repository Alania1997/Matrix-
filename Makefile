# Переменные для компилятора и флагов
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -fprofile-arcs -ftest-coverage
LDFLAGS = -lgtest -lgtest_main -pthread

# Директории
BUILD_DIR = build

# Файлы
SRC_FILES = S21Matrix.cpp s21_overloading.cpp
TEST_FILE = test.cpp
OBJ_FILES = $(BUILD_DIR)/S21Matrix.o $(BUILD_DIR)/s21_overloading.o
OBJ_TEST = $(BUILD_DIR)/test.o

# Исполняемый файл
EXEC = $(BUILD_DIR)/matrix_test
S21 = s21_matrix_oop.a

# Основная цель - сборка тестов
all: $(S21)

# Сборка исполняемого файла с тестами
$(S21): $(OBJ_FILES) $(OBJ_TEST)
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) $(OBJ_TEST) -o $(EXEC) $(LDFLAGS)

# Правило для компиляции исходного файла S21Matrix.cpp
$(BUILD_DIR)/S21Matrix.o: S21Matrix.cpp s21_matrix_oop.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c S21Matrix.cpp -o $(BUILD_DIR)/S21Matrix.o

# Правило для компиляции файла s21_overloading.cpp
$(BUILD_DIR)/s21_overloading.o: s21_overloading.cpp s21_matrix_oop.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c s21_overloading.cpp -o $(BUILD_DIR)/s21_overloading.o

# Правило для компиляции тестового файла test.cpp
$(BUILD_DIR)/test.o: test.cpp s21_matrix_oop.h
	@mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c test.cpp -o $(BUILD_DIR)/test.o

# Очистка всех сгенерированных файлов
clean:
	rm -rf $(BUILD_DIR)/*.o $(EXEC) *.gcda *.gcno *.gcov report
	rm -rf $(BUILD_DIR)/*.o $(EXEC) *.gcda *.gcno *.gcov report coverage.info

# Запуск тестов
test: $(S21)
	./$(EXEC)

gcov_report: test
# Собираем данные покрытия с помощью lcov, игнорируя ошибки несоответствий
	lcov --capture --directory . --output-file coverage.info --no-external --ignore-errors inconsistent
# Генерируем HTML-отчет
	genhtml coverage.info --output-directory report
# Открываем отчет, если возможно
	@xdg-open report/index.html || open report/index.html || echo "Откройте report/index.html для просмотра отчета покрытия."


# Форматирование исходников с помощью clang-format
style:
	clang-format -n $(SRC_FILES) $(TEST_FILE) s21_matrix_oop.h
	clang-format -i $(SRC_FILES) $(TEST_FILE) s21_matrix_oop.h
