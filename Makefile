CXX      := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -g -O0
LDFLAGS  :=

TARGET   := campusguard
BUILD    := build

SRCS := \
    mainDemo.cpp \
    CommandInvoker.cpp \
    IncidentCommand.cpp \
    DispatchUnitCommand.cpp \
    SecureAreaCommand.cpp \
    IssueEvacuationCommand.cpp \
    CancelActionCommand.cpp \
    Incident.cpp \
    ReportedState.cpp \
    ActiveState.cpp \
    ResolvedState.cpp \
    ResponseUnit.cpp \
    MedicalTeam.cpp \
    SecurityTeam.cpp \
    FacilitiesTeam.cpp \
	AccessControlSystem.cpp \
	Colleague.cpp \
	LockdownProcedures.cpp\
    AccessControlAdapter.cpp \
    LegacyDoorSystem.cpp \
    AlertService.cpp \
    CampusIncidentCoordinator.cpp

OBJS := $(SRCS:%.cpp=$(BUILD)/%.o)

.PHONY: all clean run valgrind gdb debug

all: $(BUILD)/$(TARGET)

$(BUILD)/$(TARGET): $(OBJS)
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Built: $@"

$(BUILD)/%.o: %.cpp
	@mkdir -p $(BUILD)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: all
	./$(BUILD)/$(TARGET)

valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all \
	         --track-origins=yes --error-exitcode=1 \
	         ./$(BUILD)/$(TARGET)

gdb: all
	gdb --args ./$(BUILD)/$(TARGET)

debug:
	@echo "SRCS = $(SRCS)"
	@echo "OBJS = $(OBJS)"

clean:
	rm -rf $(BUILD)
	@echo "Cleaned."