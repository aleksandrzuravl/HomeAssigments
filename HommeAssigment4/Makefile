CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror -Wpedantic -pthread
LDFLAGS = -lgtest -lgtest_main

TARGET = main
TEST_TARGET = test_transformer

SRCS = main.cpp Transformer.cpp Autobot.cpp Decepticon.cpp Item.cpp
OBJS = $(SRCS:.cpp=.o)

TEST_SRCS = test_transformer.cpp Transformer.cpp Autobot.cpp  Decepticon.cpp Item.cpp
TEST_OBJS = $(TEST_SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

test: $(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	./$@
	rm -rf $@

clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)
