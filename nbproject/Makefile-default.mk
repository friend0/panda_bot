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
SOURCEFILES_QUOTED_IF_SPACED=AD.c BOARD.c Bot.c BotFrameworkEvents.c BotMain.c ES_CheckEvents.c ES_Framework.c ES_KeyboardInput.c ES_Queue.c ES_TattleTale.c ES_TimerService.c ES_Timers.c IO_Ports.c Motor_X_FSM.c Motor_Y_FSM.c RC_Servo.c Servo_Azimuth_FSM.c Stepper.c dee_emulation_pic32.c pwm.c serial.c i2c_master.c AccelX_SubFSM.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/AD.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/Bot.o ${OBJECTDIR}/BotFrameworkEvents.o ${OBJECTDIR}/BotMain.o ${OBJECTDIR}/ES_CheckEvents.o ${OBJECTDIR}/ES_Framework.o ${OBJECTDIR}/ES_KeyboardInput.o ${OBJECTDIR}/ES_Queue.o ${OBJECTDIR}/ES_TattleTale.o ${OBJECTDIR}/ES_TimerService.o ${OBJECTDIR}/ES_Timers.o ${OBJECTDIR}/IO_Ports.o ${OBJECTDIR}/Motor_X_FSM.o ${OBJECTDIR}/Motor_Y_FSM.o ${OBJECTDIR}/RC_Servo.o ${OBJECTDIR}/Servo_Azimuth_FSM.o ${OBJECTDIR}/Stepper.o ${OBJECTDIR}/dee_emulation_pic32.o ${OBJECTDIR}/pwm.o ${OBJECTDIR}/serial.o ${OBJECTDIR}/i2c_master.o ${OBJECTDIR}/AccelX_SubFSM.o
POSSIBLE_DEPFILES=${OBJECTDIR}/AD.o.d ${OBJECTDIR}/BOARD.o.d ${OBJECTDIR}/Bot.o.d ${OBJECTDIR}/BotFrameworkEvents.o.d ${OBJECTDIR}/BotMain.o.d ${OBJECTDIR}/ES_CheckEvents.o.d ${OBJECTDIR}/ES_Framework.o.d ${OBJECTDIR}/ES_KeyboardInput.o.d ${OBJECTDIR}/ES_Queue.o.d ${OBJECTDIR}/ES_TattleTale.o.d ${OBJECTDIR}/ES_TimerService.o.d ${OBJECTDIR}/ES_Timers.o.d ${OBJECTDIR}/IO_Ports.o.d ${OBJECTDIR}/Motor_X_FSM.o.d ${OBJECTDIR}/Motor_Y_FSM.o.d ${OBJECTDIR}/RC_Servo.o.d ${OBJECTDIR}/Servo_Azimuth_FSM.o.d ${OBJECTDIR}/Stepper.o.d ${OBJECTDIR}/dee_emulation_pic32.o.d ${OBJECTDIR}/pwm.o.d ${OBJECTDIR}/serial.o.d ${OBJECTDIR}/i2c_master.o.d ${OBJECTDIR}/AccelX_SubFSM.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/AD.o ${OBJECTDIR}/BOARD.o ${OBJECTDIR}/Bot.o ${OBJECTDIR}/BotFrameworkEvents.o ${OBJECTDIR}/BotMain.o ${OBJECTDIR}/ES_CheckEvents.o ${OBJECTDIR}/ES_Framework.o ${OBJECTDIR}/ES_KeyboardInput.o ${OBJECTDIR}/ES_Queue.o ${OBJECTDIR}/ES_TattleTale.o ${OBJECTDIR}/ES_TimerService.o ${OBJECTDIR}/ES_Timers.o ${OBJECTDIR}/IO_Ports.o ${OBJECTDIR}/Motor_X_FSM.o ${OBJECTDIR}/Motor_Y_FSM.o ${OBJECTDIR}/RC_Servo.o ${OBJECTDIR}/Servo_Azimuth_FSM.o ${OBJECTDIR}/Stepper.o ${OBJECTDIR}/dee_emulation_pic32.o ${OBJECTDIR}/pwm.o ${OBJECTDIR}/serial.o ${OBJECTDIR}/i2c_master.o ${OBJECTDIR}/AccelX_SubFSM.o

# Source Files
SOURCEFILES=AD.c BOARD.c Bot.c BotFrameworkEvents.c BotMain.c ES_CheckEvents.c ES_Framework.c ES_KeyboardInput.c ES_Queue.c ES_TattleTale.c ES_TimerService.c ES_Timers.c IO_Ports.c Motor_X_FSM.c Motor_Y_FSM.c RC_Servo.c Servo_Azimuth_FSM.c Stepper.c dee_emulation_pic32.c pwm.c serial.c i2c_master.c AccelX_SubFSM.c


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
${OBJECTDIR}/AD.o: AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AD.o.d 
	@${RM} ${OBJECTDIR}/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/AD.o.d" -o ${OBJECTDIR}/AD.o AD.c   
	
${OBJECTDIR}/BOARD.o: BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c   
	
${OBJECTDIR}/Bot.o: Bot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Bot.o.d 
	@${RM} ${OBJECTDIR}/Bot.o 
	@${FIXDEPS} "${OBJECTDIR}/Bot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Bot.o.d" -o ${OBJECTDIR}/Bot.o Bot.c   
	
${OBJECTDIR}/BotFrameworkEvents.o: BotFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BotFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/BotFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/BotFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/BotFrameworkEvents.o.d" -o ${OBJECTDIR}/BotFrameworkEvents.o BotFrameworkEvents.c   
	
${OBJECTDIR}/BotMain.o: BotMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BotMain.o.d 
	@${RM} ${OBJECTDIR}/BotMain.o 
	@${FIXDEPS} "${OBJECTDIR}/BotMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/BotMain.o.d" -o ${OBJECTDIR}/BotMain.o BotMain.c   
	
${OBJECTDIR}/ES_CheckEvents.o: ES_CheckEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_CheckEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ES_CheckEvents.o ES_CheckEvents.c   
	
${OBJECTDIR}/ES_Framework.o: ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_Framework.o.d" -o ${OBJECTDIR}/ES_Framework.o ES_Framework.c   
	
${OBJECTDIR}/ES_KeyboardInput.o: ES_KeyboardInput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_KeyboardInput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ES_KeyboardInput.o ES_KeyboardInput.c   
	
${OBJECTDIR}/ES_Queue.o: ES_Queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ES_Queue.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_Queue.o.d" -o ${OBJECTDIR}/ES_Queue.o ES_Queue.c   
	
${OBJECTDIR}/ES_TattleTale.o: ES_TattleTale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_TattleTale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_TattleTale.o.d" -o ${OBJECTDIR}/ES_TattleTale.o ES_TattleTale.c   
	
${OBJECTDIR}/ES_TimerService.o: ES_TimerService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_TimerService.o.d 
	@${RM} ${OBJECTDIR}/ES_TimerService.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_TimerService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_TimerService.o.d" -o ${OBJECTDIR}/ES_TimerService.o ES_TimerService.c   
	
${OBJECTDIR}/ES_Timers.o: ES_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ES_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_Timers.o.d" -o ${OBJECTDIR}/ES_Timers.o ES_Timers.c   
	
${OBJECTDIR}/IO_Ports.o: IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/IO_Ports.o.d" -o ${OBJECTDIR}/IO_Ports.o IO_Ports.c   
	
${OBJECTDIR}/Motor_X_FSM.o: Motor_X_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motor_X_FSM.o.d 
	@${RM} ${OBJECTDIR}/Motor_X_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/Motor_X_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Motor_X_FSM.o.d" -o ${OBJECTDIR}/Motor_X_FSM.o Motor_X_FSM.c   
	
${OBJECTDIR}/Motor_Y_FSM.o: Motor_Y_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motor_Y_FSM.o.d 
	@${RM} ${OBJECTDIR}/Motor_Y_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/Motor_Y_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Motor_Y_FSM.o.d" -o ${OBJECTDIR}/Motor_Y_FSM.o Motor_Y_FSM.c   
	
${OBJECTDIR}/RC_Servo.o: RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/RC_Servo.o.d" -o ${OBJECTDIR}/RC_Servo.o RC_Servo.c   
	
${OBJECTDIR}/Servo_Azimuth_FSM.o: Servo_Azimuth_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Servo_Azimuth_FSM.o.d 
	@${RM} ${OBJECTDIR}/Servo_Azimuth_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/Servo_Azimuth_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Servo_Azimuth_FSM.o.d" -o ${OBJECTDIR}/Servo_Azimuth_FSM.o Servo_Azimuth_FSM.c   
	
${OBJECTDIR}/Stepper.o: Stepper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Stepper.o.d 
	@${RM} ${OBJECTDIR}/Stepper.o 
	@${FIXDEPS} "${OBJECTDIR}/Stepper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Stepper.o.d" -o ${OBJECTDIR}/Stepper.o Stepper.c   
	
${OBJECTDIR}/dee_emulation_pic32.o: dee_emulation_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/dee_emulation_pic32.o.d 
	@${RM} ${OBJECTDIR}/dee_emulation_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/dee_emulation_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/dee_emulation_pic32.o.d" -o ${OBJECTDIR}/dee_emulation_pic32.o dee_emulation_pic32.c   
	
${OBJECTDIR}/pwm.o: pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/pwm.o.d" -o ${OBJECTDIR}/pwm.o pwm.c   
	
${OBJECTDIR}/serial.o: serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/serial.o.d 
	@${RM} ${OBJECTDIR}/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/serial.o.d" -o ${OBJECTDIR}/serial.o serial.c   
	
${OBJECTDIR}/i2c_master.o: i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/i2c_master.o.d" -o ${OBJECTDIR}/i2c_master.o i2c_master.c   
	
${OBJECTDIR}/AccelX_SubFSM.o: AccelX_SubFSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AccelX_SubFSM.o.d 
	@${RM} ${OBJECTDIR}/AccelX_SubFSM.o 
	@${FIXDEPS} "${OBJECTDIR}/AccelX_SubFSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/AccelX_SubFSM.o.d" -o ${OBJECTDIR}/AccelX_SubFSM.o AccelX_SubFSM.c   
	
else
${OBJECTDIR}/AD.o: AD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AD.o.d 
	@${RM} ${OBJECTDIR}/AD.o 
	@${FIXDEPS} "${OBJECTDIR}/AD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/AD.o.d" -o ${OBJECTDIR}/AD.o AD.c   
	
${OBJECTDIR}/BOARD.o: BOARD.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BOARD.o.d 
	@${RM} ${OBJECTDIR}/BOARD.o 
	@${FIXDEPS} "${OBJECTDIR}/BOARD.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/BOARD.o.d" -o ${OBJECTDIR}/BOARD.o BOARD.c   
	
${OBJECTDIR}/Bot.o: Bot.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Bot.o.d 
	@${RM} ${OBJECTDIR}/Bot.o 
	@${FIXDEPS} "${OBJECTDIR}/Bot.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Bot.o.d" -o ${OBJECTDIR}/Bot.o Bot.c   
	
${OBJECTDIR}/BotFrameworkEvents.o: BotFrameworkEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BotFrameworkEvents.o.d 
	@${RM} ${OBJECTDIR}/BotFrameworkEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/BotFrameworkEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/BotFrameworkEvents.o.d" -o ${OBJECTDIR}/BotFrameworkEvents.o BotFrameworkEvents.c   
	
${OBJECTDIR}/BotMain.o: BotMain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/BotMain.o.d 
	@${RM} ${OBJECTDIR}/BotMain.o 
	@${FIXDEPS} "${OBJECTDIR}/BotMain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/BotMain.o.d" -o ${OBJECTDIR}/BotMain.o BotMain.c   
	
${OBJECTDIR}/ES_CheckEvents.o: ES_CheckEvents.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o.d 
	@${RM} ${OBJECTDIR}/ES_CheckEvents.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_CheckEvents.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_CheckEvents.o.d" -o ${OBJECTDIR}/ES_CheckEvents.o ES_CheckEvents.c   
	
${OBJECTDIR}/ES_Framework.o: ES_Framework.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_Framework.o.d 
	@${RM} ${OBJECTDIR}/ES_Framework.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Framework.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_Framework.o.d" -o ${OBJECTDIR}/ES_Framework.o ES_Framework.c   
	
${OBJECTDIR}/ES_KeyboardInput.o: ES_KeyboardInput.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o.d 
	@${RM} ${OBJECTDIR}/ES_KeyboardInput.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_KeyboardInput.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_KeyboardInput.o.d" -o ${OBJECTDIR}/ES_KeyboardInput.o ES_KeyboardInput.c   
	
${OBJECTDIR}/ES_Queue.o: ES_Queue.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_Queue.o.d 
	@${RM} ${OBJECTDIR}/ES_Queue.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Queue.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_Queue.o.d" -o ${OBJECTDIR}/ES_Queue.o ES_Queue.c   
	
${OBJECTDIR}/ES_TattleTale.o: ES_TattleTale.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o.d 
	@${RM} ${OBJECTDIR}/ES_TattleTale.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_TattleTale.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_TattleTale.o.d" -o ${OBJECTDIR}/ES_TattleTale.o ES_TattleTale.c   
	
${OBJECTDIR}/ES_TimerService.o: ES_TimerService.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_TimerService.o.d 
	@${RM} ${OBJECTDIR}/ES_TimerService.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_TimerService.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_TimerService.o.d" -o ${OBJECTDIR}/ES_TimerService.o ES_TimerService.c   
	
${OBJECTDIR}/ES_Timers.o: ES_Timers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/ES_Timers.o.d 
	@${RM} ${OBJECTDIR}/ES_Timers.o 
	@${FIXDEPS} "${OBJECTDIR}/ES_Timers.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/ES_Timers.o.d" -o ${OBJECTDIR}/ES_Timers.o ES_Timers.c   
	
${OBJECTDIR}/IO_Ports.o: IO_Ports.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/IO_Ports.o.d 
	@${RM} ${OBJECTDIR}/IO_Ports.o 
	@${FIXDEPS} "${OBJECTDIR}/IO_Ports.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/IO_Ports.o.d" -o ${OBJECTDIR}/IO_Ports.o IO_Ports.c   
	
${OBJECTDIR}/Motor_X_FSM.o: Motor_X_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motor_X_FSM.o.d 
	@${RM} ${OBJECTDIR}/Motor_X_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/Motor_X_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Motor_X_FSM.o.d" -o ${OBJECTDIR}/Motor_X_FSM.o Motor_X_FSM.c   
	
${OBJECTDIR}/Motor_Y_FSM.o: Motor_Y_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Motor_Y_FSM.o.d 
	@${RM} ${OBJECTDIR}/Motor_Y_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/Motor_Y_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Motor_Y_FSM.o.d" -o ${OBJECTDIR}/Motor_Y_FSM.o Motor_Y_FSM.c   
	
${OBJECTDIR}/RC_Servo.o: RC_Servo.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/RC_Servo.o.d 
	@${RM} ${OBJECTDIR}/RC_Servo.o 
	@${FIXDEPS} "${OBJECTDIR}/RC_Servo.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/RC_Servo.o.d" -o ${OBJECTDIR}/RC_Servo.o RC_Servo.c   
	
${OBJECTDIR}/Servo_Azimuth_FSM.o: Servo_Azimuth_FSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Servo_Azimuth_FSM.o.d 
	@${RM} ${OBJECTDIR}/Servo_Azimuth_FSM.o 
	@${FIXDEPS} "${OBJECTDIR}/Servo_Azimuth_FSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Servo_Azimuth_FSM.o.d" -o ${OBJECTDIR}/Servo_Azimuth_FSM.o Servo_Azimuth_FSM.c   
	
${OBJECTDIR}/Stepper.o: Stepper.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/Stepper.o.d 
	@${RM} ${OBJECTDIR}/Stepper.o 
	@${FIXDEPS} "${OBJECTDIR}/Stepper.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/Stepper.o.d" -o ${OBJECTDIR}/Stepper.o Stepper.c   
	
${OBJECTDIR}/dee_emulation_pic32.o: dee_emulation_pic32.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/dee_emulation_pic32.o.d 
	@${RM} ${OBJECTDIR}/dee_emulation_pic32.o 
	@${FIXDEPS} "${OBJECTDIR}/dee_emulation_pic32.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/dee_emulation_pic32.o.d" -o ${OBJECTDIR}/dee_emulation_pic32.o dee_emulation_pic32.c   
	
${OBJECTDIR}/pwm.o: pwm.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/pwm.o.d 
	@${RM} ${OBJECTDIR}/pwm.o 
	@${FIXDEPS} "${OBJECTDIR}/pwm.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/pwm.o.d" -o ${OBJECTDIR}/pwm.o pwm.c   
	
${OBJECTDIR}/serial.o: serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/serial.o.d 
	@${RM} ${OBJECTDIR}/serial.o 
	@${FIXDEPS} "${OBJECTDIR}/serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/serial.o.d" -o ${OBJECTDIR}/serial.o serial.c   
	
${OBJECTDIR}/i2c_master.o: i2c_master.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/i2c_master.o.d 
	@${RM} ${OBJECTDIR}/i2c_master.o 
	@${FIXDEPS} "${OBJECTDIR}/i2c_master.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/i2c_master.o.d" -o ${OBJECTDIR}/i2c_master.o i2c_master.c   
	
${OBJECTDIR}/AccelX_SubFSM.o: AccelX_SubFSM.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} ${OBJECTDIR} 
	@${RM} ${OBJECTDIR}/AccelX_SubFSM.o.d 
	@${RM} ${OBJECTDIR}/AccelX_SubFSM.o 
	@${FIXDEPS} "${OBJECTDIR}/AccelX_SubFSM.o.d" $(SILENT) -rsi ${MP_CC_DIR}../  -c ${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -I"/Users/ryanarodriguez/MPLABX/MPLABXProjects/panda_bot.X" -MMD -MF "${OBJECTDIR}/AccelX_SubFSM.o.d" -o ${OBJECTDIR}/AccelX_SubFSM.o AccelX_SubFSM.c   
	
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
