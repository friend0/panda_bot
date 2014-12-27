#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ES_Files/ES_CheckEvents.c ES_Files/ES_Framework.c ES_Files/ES_KeyboardInput.c ES_Files/ES_LookupTables.c ES_Files/ES_PostList.c ES_Files/ES_Queue.c ES_Files/ES_TattleTale.c ES_Files/ES_Timers.c ES_Files/ES_TimerService.c FSMs/Bot.c FSMs/BotFrameworkEvents.c FSMs/BotMain.c FSMs/Motor_X_FSM.c FSMs/Motor_Y_FSM.c FSMs/Presets_FSM.c FSMs/Servo_Azimuth_FSM.c hardware/AD.c hardware/BOARD.c hardware/dee_emulation_pic32.c hardware/i2c.c hardware/i2c_master.c hardware/IO_Ports.c hardware/LED.c hardware/pwm.c hardware/RC_Servo.c hardware/serial.c hardware/Stepper.c hardware/timers.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ES_Files/ES_CheckEvents.o ${OBJECTDIR}/ES_Files/ES_Framework.o ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o ${OBJECTDIR}/ES_Files/ES_LookupTables.o ${OBJECTDIR}/ES_Files/ES_PostList.o ${OBJECTDIR}/ES_Files/ES_Queue.o ${OBJECTDIR}/ES_Files/ES_TattleTale.o ${OBJECTDIR}/ES_Files/ES_Timers.o ${OBJECTDIR}/ES_Files/ES_TimerService.o ${OBJECTDIR}/FSMs/Bot.o ${OBJECTDIR}/FSMs/BotFrameworkEvents.o ${OBJECTDIR}/FSMs/BotMain.o ${OBJECTDIR}/FSMs/Motor_X_FSM.o ${OBJECTDIR}/FSMs/Motor_Y_FSM.o ${OBJECTDIR}/FSMs/Presets_FSM.o ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o ${OBJECTDIR}/hardware/AD.o ${OBJECTDIR}/hardware/BOARD.o ${OBJECTDIR}/hardware/dee_emulation_pic32.o ${OBJECTDIR}/hardware/i2c.o ${OBJECTDIR}/hardware/i2c_master.o ${OBJECTDIR}/hardware/IO_Ports.o ${OBJECTDIR}/hardware/LED.o ${OBJECTDIR}/hardware/pwm.o ${OBJECTDIR}/hardware/RC_Servo.o ${OBJECTDIR}/hardware/serial.o ${OBJECTDIR}/hardware/Stepper.o ${OBJECTDIR}/hardware/timers.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d ${OBJECTDIR}/ES_Files/ES_Framework.o.d ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d ${OBJECTDIR}/ES_Files/ES_LookupTables.o.d ${OBJECTDIR}/ES_Files/ES_PostList.o.d ${OBJECTDIR}/ES_Files/ES_Queue.o.d ${OBJECTDIR}/ES_Files/ES_TattleTale.o.d ${OBJECTDIR}/ES_Files/ES_Timers.o.d ${OBJECTDIR}/ES_Files/ES_TimerService.o.d ${OBJECTDIR}/FSMs/Bot.o.d ${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d ${OBJECTDIR}/FSMs/BotMain.o.d ${OBJECTDIR}/FSMs/Motor_X_FSM.o.d ${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d ${OBJECTDIR}/FSMs/Presets_FSM.o.d ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d ${OBJECTDIR}/hardware/AD.o.d ${OBJECTDIR}/hardware/BOARD.o.d ${OBJECTDIR}/hardware/dee_emulation_pic32.o.d ${OBJECTDIR}/hardware/i2c.o.d ${OBJECTDIR}/hardware/i2c_master.o.d ${OBJECTDIR}/hardware/IO_Ports.o.d ${OBJECTDIR}/hardware/LED.o.d ${OBJECTDIR}/hardware/pwm.o.d ${OBJECTDIR}/hardware/RC_Servo.o.d ${OBJECTDIR}/hardware/serial.o.d ${OBJECTDIR}/hardware/Stepper.o.d ${OBJECTDIR}/hardware/timers.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ES_Files/ES_CheckEvents.o ${OBJECTDIR}/ES_Files/ES_Framework.o ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o ${OBJECTDIR}/ES_Files/ES_LookupTables.o ${OBJECTDIR}/ES_Files/ES_PostList.o ${OBJECTDIR}/ES_Files/ES_Queue.o ${OBJECTDIR}/ES_Files/ES_TattleTale.o ${OBJECTDIR}/ES_Files/ES_Timers.o ${OBJECTDIR}/ES_Files/ES_TimerService.o ${OBJECTDIR}/FSMs/Bot.o ${OBJECTDIR}/FSMs/BotFrameworkEvents.o ${OBJECTDIR}/FSMs/BotMain.o ${OBJECTDIR}/FSMs/Motor_X_FSM.o ${OBJECTDIR}/FSMs/Motor_Y_FSM.o ${OBJECTDIR}/FSMs/Presets_FSM.o ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o ${OBJECTDIR}/hardware/AD.o ${OBJECTDIR}/hardware/BOARD.o ${OBJECTDIR}/hardware/dee_emulation_pic32.o ${OBJECTDIR}/hardware/i2c.o ${OBJECTDIR}/hardware/i2c_master.o ${OBJECTDIR}/hardware/IO_Ports.o ${OBJECTDIR}/hardware/LED.o ${OBJECTDIR}/hardware/pwm.o ${OBJECTDIR}/hardware/RC_Servo.o ${OBJECTDIR}/hardware/serial.o ${OBJECTDIR}/hardware/Stepper.o ${OBJECTDIR}/hardware/timers.o

# Source Files
SOURCEFILES=ES_Files/ES_CheckEvents.c ES_Files/ES_Framework.c ES_Files/ES_KeyboardInput.c ES_Files/ES_LookupTables.c ES_Files/ES_PostList.c ES_Files/ES_Queue.c ES_Files/ES_TattleTale.c ES_Files/ES_Timers.c ES_Files/ES_TimerService.c FSMs/Bot.c FSMs/BotFrameworkEvents.c FSMs/BotMain.c FSMs/Motor_X_FSM.c FSMs/Motor_Y_FSM.c FSMs/Presets_FSM.c FSMs/Servo_Azimuth_FSM.c hardware/AD.c hardware/BOARD.c hardware/dee_emulation_pic32.c hardware/i2c.c hardware/i2c_master.c hardware/IO_Ports.c hardware/LED.c hardware/pwm.c hardware/RC_Servo.c hardware/serial.c hardware/Stepper.c hardware/timers.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MX320F128H
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ES_Files/ES_CheckEvents.o: ES_Files/ES_CheckEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_CheckEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ES_Files/ES_CheckEvents.o ES_Files/ES_CheckEvents.c   
	
${OBJECTDIR}/ES_Files/ES_Framework.o: ES_Files/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_Framework.o.d" -o ${OBJECTDIR}/ES_Files/ES_Framework.o ES_Files/ES_Framework.c   
	
${OBJECTDIR}/ES_Files/ES_KeyboardInput.o: ES_Files/ES_KeyboardInput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o ES_Files/ES_KeyboardInput.c   
	
${OBJECTDIR}/ES_Files/ES_LookupTables.o: ES_Files/ES_LookupTables.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_LookupTables.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_LookupTables.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_LookupTables.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_LookupTables.o.d" -o ${OBJECTDIR}/ES_Files/ES_LookupTables.o ES_Files/ES_LookupTables.c   
	
${OBJECTDIR}/ES_Files/ES_PostList.o: ES_Files/ES_PostList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_PostList.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_PostList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_PostList.o.d" -o ${OBJECTDIR}/ES_Files/ES_PostList.o ES_Files/ES_PostList.c   
	
${OBJECTDIR}/ES_Files/ES_Queue.o: ES_Files/ES_Queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Queue.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_Queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_Queue.o.d" -o ${OBJECTDIR}/ES_Files/ES_Queue.o ES_Files/ES_Queue.c   
	
${OBJECTDIR}/ES_Files/ES_TattleTale.o: ES_Files/ES_TattleTale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TattleTale.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_TattleTale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_TattleTale.o.d" -o ${OBJECTDIR}/ES_Files/ES_TattleTale.o ES_Files/ES_TattleTale.c   
	
${OBJECTDIR}/ES_Files/ES_Timers.o: ES_Files/ES_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_Timers.o.d" -o ${OBJECTDIR}/ES_Files/ES_Timers.o ES_Files/ES_Timers.c   
	
${OBJECTDIR}/ES_Files/ES_TimerService.o: ES_Files/ES_TimerService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TimerService.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TimerService.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_TimerService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_TimerService.o.d" -o ${OBJECTDIR}/ES_Files/ES_TimerService.o ES_Files/ES_TimerService.c   
	
${OBJECTDIR}/FSMs/Bot.o: FSMs/Bot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Bot.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Bot.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Bot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Bot.o.d" -o ${OBJECTDIR}/FSMs/Bot.o FSMs/Bot.c   
	
${OBJECTDIR}/FSMs/BotFrameworkEvents.o: FSMs/BotFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/FSMs/BotFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d" -o ${OBJECTDIR}/FSMs/BotFrameworkEvents.o FSMs/BotFrameworkEvents.c   
	
${OBJECTDIR}/FSMs/BotMain.o: FSMs/BotMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/BotMain.o.d 
	@${RM} ${OBJECTDIR}/FSMs/BotMain.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/BotMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/BotMain.o.d" -o ${OBJECTDIR}/FSMs/BotMain.o FSMs/BotMain.c   
	
${OBJECTDIR}/FSMs/Motor_X_FSM.o: FSMs/Motor_X_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Motor_X_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Motor_X_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Motor_X_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Motor_X_FSM.o.d" -o ${OBJECTDIR}/FSMs/Motor_X_FSM.o FSMs/Motor_X_FSM.c   
	
${OBJECTDIR}/FSMs/Motor_Y_FSM.o: FSMs/Motor_Y_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Motor_Y_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d" -o ${OBJECTDIR}/FSMs/Motor_Y_FSM.o FSMs/Motor_Y_FSM.c   
	
${OBJECTDIR}/FSMs/Presets_FSM.o: FSMs/Presets_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Presets_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Presets_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Presets_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Presets_FSM.o.d" -o ${OBJECTDIR}/FSMs/Presets_FSM.o FSMs/Presets_FSM.c   
	
${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o: FSMs/Servo_Azimuth_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d" -o ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o FSMs/Servo_Azimuth_FSM.c   
	
${OBJECTDIR}/hardware/AD.o: hardware/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/AD.o.d 
	@${RM} ${OBJECTDIR}/hardware/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/AD.o.d" -o ${OBJECTDIR}/hardware/AD.o hardware/AD.c   
	
${OBJECTDIR}/hardware/BOARD.o: hardware/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/BOARD.o.d 
	@${RM} ${OBJECTDIR}/hardware/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/BOARD.o.d" -o ${OBJECTDIR}/hardware/BOARD.o hardware/BOARD.c   
	
${OBJECTDIR}/hardware/dee_emulation_pic32.o: hardware/dee_emulation_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/dee_emulation_pic32.o.d 
	@${RM} ${OBJECTDIR}/hardware/dee_emulation_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/dee_emulation_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/dee_emulation_pic32.o.d" -o ${OBJECTDIR}/hardware/dee_emulation_pic32.o hardware/dee_emulation_pic32.c   
	
${OBJECTDIR}/hardware/i2c.o: hardware/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/i2c.o.d 
	@${RM} ${OBJECTDIR}/hardware/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/i2c.o.d" -o ${OBJECTDIR}/hardware/i2c.o hardware/i2c.c   
	
${OBJECTDIR}/hardware/i2c_master.o: hardware/i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/hardware/i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/i2c_master.o.d" -o ${OBJECTDIR}/hardware/i2c_master.o hardware/i2c_master.c   
	
${OBJECTDIR}/hardware/IO_Ports.o: hardware/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/hardware/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/IO_Ports.o.d" -o ${OBJECTDIR}/hardware/IO_Ports.o hardware/IO_Ports.c   
	
${OBJECTDIR}/hardware/LED.o: hardware/LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/LED.o.d 
	@${RM} ${OBJECTDIR}/hardware/LED.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/LED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/LED.o.d" -o ${OBJECTDIR}/hardware/LED.o hardware/LED.c   
	
${OBJECTDIR}/hardware/pwm.o: hardware/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/pwm.o.d 
	@${RM} ${OBJECTDIR}/hardware/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/pwm.o.d" -o ${OBJECTDIR}/hardware/pwm.o hardware/pwm.c   
	
${OBJECTDIR}/hardware/RC_Servo.o: hardware/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/hardware/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/RC_Servo.o.d" -o ${OBJECTDIR}/hardware/RC_Servo.o hardware/RC_Servo.c   
	
${OBJECTDIR}/hardware/serial.o: hardware/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/serial.o.d 
	@${RM} ${OBJECTDIR}/hardware/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/serial.o.d" -o ${OBJECTDIR}/hardware/serial.o hardware/serial.c   
	
${OBJECTDIR}/hardware/Stepper.o: hardware/Stepper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/Stepper.o.d 
	@${RM} ${OBJECTDIR}/hardware/Stepper.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/Stepper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/Stepper.o.d" -o ${OBJECTDIR}/hardware/Stepper.o hardware/Stepper.c   
	
${OBJECTDIR}/hardware/timers.o: hardware/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/timers.o.d 
	@${RM} ${OBJECTDIR}/hardware/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/timers.o.d" -o ${OBJECTDIR}/hardware/timers.o hardware/timers.c   
	
else
${OBJECTDIR}/ES_Files/ES_CheckEvents.o: ES_Files/ES_CheckEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_CheckEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ES_Files/ES_CheckEvents.o ES_Files/ES_CheckEvents.c   
	
${OBJECTDIR}/ES_Files/ES_Framework.o: ES_Files/ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_Framework.o.d" -o ${OBJECTDIR}/ES_Files/ES_Framework.o ES_Files/ES_Framework.c   
	
${OBJECTDIR}/ES_Files/ES_KeyboardInput.o: ES_Files/ES_KeyboardInput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ES_Files/ES_KeyboardInput.o ES_Files/ES_KeyboardInput.c   
	
${OBJECTDIR}/ES_Files/ES_LookupTables.o: ES_Files/ES_LookupTables.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_LookupTables.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_LookupTables.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_LookupTables.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_LookupTables.o.d" -o ${OBJECTDIR}/ES_Files/ES_LookupTables.o ES_Files/ES_LookupTables.c   
	
${OBJECTDIR}/ES_Files/ES_PostList.o: ES_Files/ES_PostList.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_PostList.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_PostList.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_PostList.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_PostList.o.d" -o ${OBJECTDIR}/ES_Files/ES_PostList.o ES_Files/ES_PostList.c   
	
${OBJECTDIR}/ES_Files/ES_Queue.o: ES_Files/ES_Queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Queue.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_Queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_Queue.o.d" -o ${OBJECTDIR}/ES_Files/ES_Queue.o ES_Files/ES_Queue.c   
	
${OBJECTDIR}/ES_Files/ES_TattleTale.o: ES_Files/ES_TattleTale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TattleTale.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_TattleTale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_TattleTale.o.d" -o ${OBJECTDIR}/ES_Files/ES_TattleTale.o ES_Files/ES_TattleTale.c   
	
${OBJECTDIR}/ES_Files/ES_Timers.o: ES_Files/ES_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_Timers.o.d" -o ${OBJECTDIR}/ES_Files/ES_Timers.o ES_Files/ES_Timers.c   
	
${OBJECTDIR}/ES_Files/ES_TimerService.o: ES_Files/ES_TimerService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/ES_Files 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TimerService.o.d 
	@${RM} ${OBJECTDIR}/ES_Files/ES_TimerService.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Files/ES_TimerService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/ES_Files/ES_TimerService.o.d" -o ${OBJECTDIR}/ES_Files/ES_TimerService.o ES_Files/ES_TimerService.c   
	
${OBJECTDIR}/FSMs/Bot.o: FSMs/Bot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Bot.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Bot.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Bot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Bot.o.d" -o ${OBJECTDIR}/FSMs/Bot.o FSMs/Bot.c   
	
${OBJECTDIR}/FSMs/BotFrameworkEvents.o: FSMs/BotFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/FSMs/BotFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/BotFrameworkEvents.o.d" -o ${OBJECTDIR}/FSMs/BotFrameworkEvents.o FSMs/BotFrameworkEvents.c   
	
${OBJECTDIR}/FSMs/BotMain.o: FSMs/BotMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/BotMain.o.d 
	@${RM} ${OBJECTDIR}/FSMs/BotMain.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/BotMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/BotMain.o.d" -o ${OBJECTDIR}/FSMs/BotMain.o FSMs/BotMain.c   
	
${OBJECTDIR}/FSMs/Motor_X_FSM.o: FSMs/Motor_X_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Motor_X_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Motor_X_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Motor_X_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Motor_X_FSM.o.d" -o ${OBJECTDIR}/FSMs/Motor_X_FSM.o FSMs/Motor_X_FSM.c   
	
${OBJECTDIR}/FSMs/Motor_Y_FSM.o: FSMs/Motor_Y_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Motor_Y_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Motor_Y_FSM.o.d" -o ${OBJECTDIR}/FSMs/Motor_Y_FSM.o FSMs/Motor_Y_FSM.c   
	
${OBJECTDIR}/FSMs/Presets_FSM.o: FSMs/Presets_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Presets_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Presets_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Presets_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Presets_FSM.o.d" -o ${OBJECTDIR}/FSMs/Presets_FSM.o FSMs/Presets_FSM.c   
	
${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o: FSMs/Servo_Azimuth_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/FSMs 
	@${RM} ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d 
	@${RM} ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o.d" -o ${OBJECTDIR}/FSMs/Servo_Azimuth_FSM.o FSMs/Servo_Azimuth_FSM.c   
	
${OBJECTDIR}/hardware/AD.o: hardware/AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/AD.o.d 
	@${RM} ${OBJECTDIR}/hardware/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/AD.o.d" -o ${OBJECTDIR}/hardware/AD.o hardware/AD.c   
	
${OBJECTDIR}/hardware/BOARD.o: hardware/BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/BOARD.o.d 
	@${RM} ${OBJECTDIR}/hardware/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/BOARD.o.d" -o ${OBJECTDIR}/hardware/BOARD.o hardware/BOARD.c   
	
${OBJECTDIR}/hardware/dee_emulation_pic32.o: hardware/dee_emulation_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/dee_emulation_pic32.o.d 
	@${RM} ${OBJECTDIR}/hardware/dee_emulation_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/dee_emulation_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/dee_emulation_pic32.o.d" -o ${OBJECTDIR}/hardware/dee_emulation_pic32.o hardware/dee_emulation_pic32.c   
	
${OBJECTDIR}/hardware/i2c.o: hardware/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/i2c.o.d 
	@${RM} ${OBJECTDIR}/hardware/i2c.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/i2c.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/i2c.o.d" -o ${OBJECTDIR}/hardware/i2c.o hardware/i2c.c   
	
${OBJECTDIR}/hardware/i2c_master.o: hardware/i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/hardware/i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/i2c_master.o.d" -o ${OBJECTDIR}/hardware/i2c_master.o hardware/i2c_master.c   
	
${OBJECTDIR}/hardware/IO_Ports.o: hardware/IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/hardware/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/IO_Ports.o.d" -o ${OBJECTDIR}/hardware/IO_Ports.o hardware/IO_Ports.c   
	
${OBJECTDIR}/hardware/LED.o: hardware/LED.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/LED.o.d 
	@${RM} ${OBJECTDIR}/hardware/LED.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/LED.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/LED.o.d" -o ${OBJECTDIR}/hardware/LED.o hardware/LED.c   
	
${OBJECTDIR}/hardware/pwm.o: hardware/pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/pwm.o.d 
	@${RM} ${OBJECTDIR}/hardware/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/pwm.o.d" -o ${OBJECTDIR}/hardware/pwm.o hardware/pwm.c   
	
${OBJECTDIR}/hardware/RC_Servo.o: hardware/RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/hardware/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/RC_Servo.o.d" -o ${OBJECTDIR}/hardware/RC_Servo.o hardware/RC_Servo.c   
	
${OBJECTDIR}/hardware/serial.o: hardware/serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/serial.o.d 
	@${RM} ${OBJECTDIR}/hardware/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/serial.o.d" -o ${OBJECTDIR}/hardware/serial.o hardware/serial.c   
	
${OBJECTDIR}/hardware/Stepper.o: hardware/Stepper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/Stepper.o.d 
	@${RM} ${OBJECTDIR}/hardware/Stepper.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/Stepper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/Stepper.o.d" -o ${OBJECTDIR}/hardware/Stepper.o hardware/Stepper.c   
	
${OBJECTDIR}/hardware/timers.o: hardware/timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR}/hardware 
	@${RM} ${OBJECTDIR}/hardware/timers.o.d 
	@${RM} ${OBJECTDIR}/hardware/timers.o 
	@${FIXDEPS} "${OBJECTDIR}/hardware/timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/ES_Files" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/FSMs" -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X/hardware" -MMD -MF "${OBJECTDIR}/hardware/timers.o.d" -o ${OBJECTDIR}/hardware/timers.o hardware/timers.c   
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}           -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC02000:0x1FC02FEF -mreserve=boot@0x1FC02000:0x1FC024FF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"
	${MP_CC_DIR}/xc32-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/panda_bot.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
