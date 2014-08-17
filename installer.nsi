; example2.nsi
;
; This script is based on example1.nsi, but it remember the directory,
; has uninstall support and (optionally) installs start menu shortcuts.
;
; It will install example2.nsi into a directory that the user selects,

;--------------------------------
!include "UninstallLog.nsh"
;--------------------------------
; Configure UnInstall log to only remove what is installed
;--------------------------------
  ;Set the name of the uninstall log
    !define UninstLog "uninstall.log"
    Var UninstLog
  ;The root registry to write to
    !define REG_ROOT "HKLM"
  ;The registry path to write to
    !define REG_APP_PATH "SOFTWARE\appname"

  ;Uninstall log file missing.
    LangString UninstLogMissing ${LANG_ENGLISH} "${UninstLog} not found!$\r$\nUninstallation cannot proceed!"

  ;AddItem macro
    !define AddItem "!insertmacro AddItem"

  ;BackupFile macro
    !define BackupFile "!insertmacro BackupFile"

  ;BackupFiles macro
    !define BackupFiles "!insertmacro BackupFiles"

  ;Copy files macro
    !define CopyFiles "!insertmacro CopyFiles"

  ;CreateDirectory macro
    !define CreateDirectory "!insertmacro CreateDirectory"

  ;CreateShortcut macro
    !define CreateShortcut "!insertmacro CreateShortcut"

  ;File macro
    !define File "!insertmacro File"

  ;Rename macro
    !define Rename "!insertmacro Rename"

  ;RestoreFile macro
    !define RestoreFile "!insertmacro RestoreFile"

  ;RestoreFiles macro
    !define RestoreFiles "!insertmacro RestoreFiles"

  ;SetOutPath macro
    !define SetOutPath "!insertmacro SetOutPath"

  ;WriteRegDWORD macro
    !define WriteRegDWORD "!insertmacro WriteRegDWORD"

  ;WriteRegStr macro
    !define WriteRegStr "!insertmacro WriteRegStr"

  ;WriteUninstaller macro
    !define WriteUninstaller "!insertmacro WriteUninstaller"

  Section -openlogfile
    CreateDirectory "$INSTDIR"
    IfFileExists "$INSTDIR\${UninstLog}" +3
      FileOpen $UninstLog "$INSTDIR\${UninstLog}" w
    Goto +4
      SetFileAttributes "$INSTDIR\${UninstLog}" NORMAL
      FileOpen $UninstLog "$INSTDIR\${UninstLog}" a
      FileSeek $UninstLog 0 END
  SectionEnd
;--------------------------------

; The name of the installer
Name "SandKeeper"

; The file to write
OutFile "SandKeeper_Installer.exe"

; The default installation directory
InstallDir $PROGRAMFILES\SandKeeper

; Registry key to check for directory (so if you install again, it will
; overwrite the old one automatically)
InstallDirRegKey HKLM "Software\SandKeeper" "Install_Dir"

; Request application privileges for Windows Vista
RequestExecutionLevel admin

;--------------------------------

; Pages

Page components
Page directory
Page instfiles

UninstPage uninstConfirm
UninstPage instfiles

;--------------------------------

; The stuff to install
Section "SandKeeper (required)"

  SectionIn RO

  ; Set output path to the installation directory.
  ${SetOutPath} $INSTDIR

  ; Put file there
  ${File} "release\D3Dcompiler_47.dll"
  ${File} "release\icudt52.dll"
  ${File} "release\icuin52.dll"
  ${File} "release\icuuc52.dll"
  ${File} "release\libEGL.dll"
  ${File} "release\libGLESv2.dll"
  ${File} "release\Qt5Core.dll"
  ${File} "release\Qt5Gui.dll"
  ${File} "release\Qt5Multimedia.dll"
  ${File} "release\Qt5MultimediaWidgets.dll"
  ${File} "release\Qt5Network.dll"
  ${File} "release\Qt5OpenGL.dll"
  ${File} "release\Qt5Svg.dll"
  ${File} "release\Qt5Widgets.dll"
  ${File} "release\sandkeeper.exe"

  ; Write the installation path into the registry
  ${WriteRegStr} HKLM "SOFTWARE\SandKeeper" "Install_Dir" "$INSTDIR"

  ; Write the uninstall keys for Windows
  ${WriteRegStr} HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SandKeeper" "DisplayName" "SandKeeper"
  ${WriteRegStr} HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SandKeeper" "UninstallString" "$INSTDIR\uninstall.exe"
  ${WriteRegDWORD} HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SandKeeper" "NoModify" 1
  ${WriteRegDWORD} HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SandKeeper" "NoRepair" 1
  ${WriteUninstaller} "uninstall.exe"

SectionEnd

Section "dll_accessible"
  ${SetOutPath} "$INSTDIR\accessible"
  ${File} "release\accessible\qtaccessiblewidgets.dll"
SectionEnd

Section "dll_platforms"
  ${SetOutPath} "$INSTDIR\platforms"
  ${File} "release\platforms\qwindows.dll"
SectionEnd

Section "dll_audio"
  ${SetOutPath} "$INSTDIR\audio"
  ${File} "release\audio\qtaudio_windows.dll"
SectionEnd

Section "dll_bearer"
  ${SetOutPath} "$INSTDIR\bearer"
  ${File} "release\bearer\qgenericbearer.dll"
  ${File} "release\bearer\qnativewifibearer.dll"
SectionEnd

Section "Dll_mediaservice"
  ${SetOutPath} "$INSTDIR\mediaservice"
  ${File} "release\mediaservice\dsengine.dll"
  ${File} "release\mediaservice\qtmedia_audioengine.dll"
  ${File} "release\mediaservice\wmfengine.dll"
SectionEnd

Section "dll_imageformats"
  ${SetOutPath} "$INSTDIR\imageformats"
  ${File} "release\imageformats\qdds.dll"
  ${File} "release\imageformats\qgif.dll"
  ${File} "release\imageformats\qicns.dll"
  ${File} "release\imageformats\qico.dll"
  ${File} "release\imageformats\qjp2.dll"
  ${File} "release\imageformats\qjpeg.dll"
  ${File} "release\imageformats\qmng.dll"
  ${File} "release\imageformats\qsvg.dll"
  ${File} "release\imageformats\qtga.dll"
  ${File} "release\imageformats\qtiff.dll"
  ${File} "release\imageformats\qwbmp.dll"
  ${File} "release\imageformats\qwebp.dll"
SectionEnd

Section "dll_iconengines"
  ${SetOutPath} "$INSTDIR\iconengines"
  ${File} "release\iconengines\qsvgicon.dll"
SectionEnd

Section "dll_playlistformats"
  ${SetOutPath} "$INSTDIR\playlistformats"
  ${File} "release\playlistformats\qtmultimedia_m3u.dll"
SectionEnd

; Optional section (can be disabled by the user)
Section "Start Menu Shortcuts"

  ${CreateDirectory} "$SMPROGRAMS\SandKeeper"
  ${CreateShortcut} "$SMPROGRAMS\SandKeeper\Uninstall.lnk" "$INSTDIR\uninstall.exe" "" "$INSTDIR\uninstall.exe" 0
  ${CreateShortcut} "$SMPROGRAMS\SandKeeper\SandKeeper.lnk" "$INSTDIR\sandkeeper.exe" "" "$INSTDIR\sandkeeper.exe" 0

SectionEnd


;--------------------------------
; Uninstaller
;--------------------------------
Section Uninstall
  ;Can't uninstall if uninstall log is missing!
  IfFileExists "$INSTDIR\${UninstLog}" +3
    MessageBox MB_OK|MB_ICONSTOP "$(UninstLogMissing)"
      Abort

  Push $R0
  Push $R1
  Push $R2
  SetFileAttributes "$INSTDIR\${UninstLog}" NORMAL
  FileOpen $UninstLog "$INSTDIR\${UninstLog}" r
  StrCpy $R1 -1

  GetLineCount:
    ClearErrors
    FileRead $UninstLog $R0
    IntOp $R1 $R1 + 1
    StrCpy $R0 $R0 -2
    Push $R0
    IfErrors 0 GetLineCount

  Pop $R0

  LoopRead:
    StrCmp $R1 0 LoopDone
    Pop $R0

    IfFileExists "$R0\*.*" 0 +3
      RMDir $R0  #is dir
    Goto +9
    IfFileExists $R0 0 +3
      Delete $R0 #is file
    Goto +6
    StrCmp $R0 "${REG_ROOT} ${REG_APP_PATH}" 0 +3
      DeleteRegKey ${REG_ROOT} "${REG_APP_PATH}" #is Reg Element
    Goto +3
    StrCmp $R0 "${REG_ROOT} ${UNINSTALL_PATH}" 0 +2
      DeleteRegKey ${REG_ROOT} "${UNINSTALL_PATH}" #is Reg Element

    IntOp $R1 $R1 - 1
    Goto LoopRead
  LoopDone:
  FileClose $UninstLog
  Delete "$INSTDIR\${UninstLog}"
  RMDir "$INSTDIR"
  Pop $R2
  Pop $R1
  Pop $R0

  ;Remove registry keys
    ;DeleteRegKey ${REG_ROOT} "${REG_APP_PATH}"
    ;DeleteRegKey ${REG_ROOT} "${UNINSTALL_PATH}"
SectionEnd

;--------------------------------

; Uninstaller

;Section "Uninstall"
;
;  ; Remove registry keys
;  DeleteRegKey HKLM "Software\Microsoft\Windows\CurrentVersion\Uninstall\SandKeeper"
;  DeleteRegKey HKLM SOFTWARE\SandKeeper
;
;  ; Remove files and uninstaller
;  Delete $INSTDIR\*.*
;
;  ; Remove shortcuts, if any
;  Delete "$SMPROGRAMS\SandKeeper\*.*"
;
;  ; Remove directories used
;  RMDir "$SMPROGRAMS\SandKeeper"
;  RMDir "$INSTDIR"
;
;SectionEnd
