/*
    Copyright (C) 2004-2008  Martin Jolicoeur (snmpb1@gmail.com) 

    This file is part of the SnmpB project 
    (http://sourceforge.net/projects/snmpb)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef SNMPB_H
#define SNMPB_H

#include "ui_mainw.h"

class MibModule;
class Trap;
class Agent;
class Graph;
class MibEditor;
class LogSnmpb;
class Discovery;
class AgentProfileManager;
class USMProfileManager;
class Preferences;

class Snmpb: public QObject
{
    Q_OBJECT
    
public:
    Snmpb(QMainWindow *mw);
    Ui_MainW* MainUI(void);
    Agent* AgentObj(void);
    Trap* TrapObj(void);
    MibViewLoader* MibLoaderObj(void);
    MibModule* MibModuleObj(void);
    AgentProfileManager* APManagerObj(void);
    USMProfileManager* UPManagerObj(void);
    Preferences* PreferencesObj(void);

    void CheckForConfigFiles(void);
    QString GetBootCounterConfigFile(void);
    QString GetMibConfigFile(void);
    QString GetPathConfigFile(void);
    QString GetUsmUsersConfigFile(void);
    QString GetAgentsConfigFile(void);
    QString GetPrefsConfigFile(void);
    QString GetLogConfigFile(void);

public slots:
    void TreeTabSelected(void);
    void ManageAgentProfiles(bool);
    void ManageUSMProfiles(bool);
    void ManagePreferences(bool);
    void AboutBox(bool);

private:
    Ui_MainW w;
    AgentProfileManager *apm;
    USMProfileManager *upm;
    Preferences *prefs;

    MibModule *modules;
    MibViewLoader loader;
    Trap *trap;
    Agent *agent;
    Graph *graph;
    MibEditor *editor;
    LogSnmpb *logsnmpb;
    Discovery *discovery;
};

#endif /* SNMPB_H */

