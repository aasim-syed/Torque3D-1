//-----------------------------------------------------------------------------
// Copyright (c) 2013 GarageGames, LLC
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
//-----------------------------------------------------------------------------
#pragma once
#ifndef TERRAINMATERIALASSET_H
#define TERRAINMATERIALASSET_H

#ifndef _ASSET_BASE_H_
#include "assets/assetBase.h"
#endif

#ifndef _ASSET_DEFINITION_H_
#include "assets/assetDefinition.h"
#endif

#ifndef _STRINGUNIT_H_
#include "string/stringUnit.h"
#endif

#ifndef _ASSET_FIELD_TYPES_H_
#include "assets/assetFieldTypes.h"
#endif

#ifndef _GFXDEVICE_H_
#include "gfx/gfxDevice.h"
#endif

#ifndef _GUI_INSPECTOR_TYPES_H_
#include "gui/editor/guiInspectorTypes.h"
#endif

#include "terrain/terrMaterial.h"

//-----------------------------------------------------------------------------
class TerrainMaterialAsset : public AssetBase
{
   typedef AssetBase Parent;

   StringTableEntry        mScriptFile;
   StringTableEntry        mScriptPath;
   StringTableEntry        mMatDefinitionName;

public:
   TerrainMaterialAsset();
   virtual ~TerrainMaterialAsset();

   /// Engine.
   static void initPersistFields();
   virtual void copyTo(SimObject* object);

   static StringTableEntry getAssetIdByMaterialName(StringTableEntry matName);

   StringTableEntry getMaterialDefinitionName() { return mMatDefinitionName; }

   void                    setScriptFile(const char* pScriptFile);
   inline StringTableEntry getScriptFile(void) const { return mScriptFile; };

   inline StringTableEntry getScriptPath(void) const { return mScriptPath; };

   /// Declare Console Object.
   DECLARE_CONOBJECT(TerrainMaterialAsset);

protected:
   virtual void initializeAsset();
   virtual void onAssetRefresh(void);

   static bool setScriptFile(void *obj, const char *index, const char *data) { static_cast<TerrainMaterialAsset*>(obj)->setScriptFile(data); return false; }
   static const char* getScriptFile(void* obj, const char* data) { return static_cast<TerrainMaterialAsset*>(obj)->getScriptFile(); }
};

DefineConsoleType(TypeTerrainMaterialAssetPtr, TerrainMaterialAsset)

//-----------------------------------------------------------------------------
// TypeAssetId GuiInspectorField Class
//-----------------------------------------------------------------------------
class GuiInspectorTypeTerrainMaterialAssetPtr : public GuiInspectorField
{
   typedef GuiInspectorField Parent;
public:

   GuiControl*       mMatEdContainer;
   GuiBitmapButtonCtrl  *mMatPreviewButton;
   GuiTextEditCtrl *mMatAssetIdTxt;

   DECLARE_CONOBJECT(GuiInspectorTypeTerrainMaterialAssetPtr);
   static void consoleInit();

   virtual GuiControl* constructEditControl();
   virtual bool updateRects();
   void setMaterialAsset(String assetId);
};

#endif // _ASSET_BASE_H_

