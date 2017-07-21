/*
 * ***** BEGIN GPL LICENSE BLOCK *****
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * The Original Code is Copyright (C) 2001-2002 by NaN Holding BV.
 * All rights reserved.
 *
 * The Original Code is: all of this file.
 *
 * Contributor(s): none yet.
 *
 * ***** END GPL LICENSE BLOCK *****
 */

/** \file RAS_MeshSlot.h
 *  \ingroup bgerast
 */

#ifndef __RAS_MESH_SLOT_H__
#define __RAS_MESH_SLOT_H__

#include "RAS_RenderNode.h"

#include <vector>

class RAS_DisplayArrayBucket;
class RAS_MeshObject;
class RAS_MeshUser;
struct DerivedMesh;

class RAS_MeshSlot
{
private:
	enum NodeType {
		NODE_NORMAL = 0,
// 		NODE_DERIVED_MESH,
		NODE_CUBE_MAP,
		NODE_TEXT,
		NODE_TYPE_MAX
	};

	RAS_MeshSlotUpwardNode m_node[NODE_TYPE_MAX];

	/// Render node utilities
	void PrepareRunNode(const RAS_MeshSlotNodeTuple& tuple);

public:
	// for rendering
	RAS_DisplayArrayBucket *m_displayArrayBucket;
	RAS_MeshObject *m_mesh;
	DerivedMesh *m_pDerivedMesh;
	RAS_MeshUser *m_meshUser;

	/// Batch index used for batching render.
	short m_batchPartIndex;

	RAS_MeshSlot(RAS_MeshObject *mesh, RAS_MeshUser *meshUser, RAS_DisplayArrayBucket *arrayBucket);
	virtual ~RAS_MeshSlot();

	void SetDisplayArrayBucket(RAS_DisplayArrayBucket *arrayBucket);

	void GenerateTree(RAS_DisplayArrayUpwardNode& root, RAS_UpwardTreeLeafs& leafs, const RAS_MeshSlotNodeTuple& tuple);

// 	void RunNodeDerivedMesh(const RAS_MeshSlotNodeTuple& tuple);
	void RunNodeCubeMap(const RAS_MeshSlotNodeTuple& tuple);
	void RunNodeText(const RAS_MeshSlotNodeTuple& tuple);
	void RunNodeNormal(const RAS_MeshSlotNodeTuple& tuple);
};

typedef std::vector<RAS_MeshSlot *> RAS_MeshSlotList;

#endif  // __RAS_MESH_SLOT_H__