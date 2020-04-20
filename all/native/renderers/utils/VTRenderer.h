/*
 * Copyright (c) 2016 CartoDB. All rights reserved.
 * Copying and using this code is allowed only according
 * to license terms, as given in https://cartodb.com/terms/
 */

#ifndef _CARTO_VTRENDERER_H_
#define _CARTO_VTRENDERER_H_

#include "renderers/utils/GLResource.h"

#include <memory>

#include <vt/GLTileRenderer.h>

namespace carto {
    
    class VTRenderer : public GLResource {
    public:
        virtual ~VTRenderer();

        std::shared_ptr<vt::GLTileRenderer> getTileRenderer() const;

    protected:
        friend GLResourceManager;

        VTRenderer(const std::shared_ptr<GLResourceManager>& manager, const std::shared_ptr<vt::TileTransformer>& tileTransformer, const boost::optional<vt::GLTileRenderer::LightingShader>& lightingShader2D, const boost::optional<vt::GLTileRenderer::LightingShader>& lightingShader3D);

        virtual void create() const;
        virtual void destroy() const;

    private:
        const std::shared_ptr<vt::TileTransformer> _tileTransformer;
        const boost::optional<vt::GLTileRenderer::LightingShader> _lightingShader2D;
        const boost::optional<vt::GLTileRenderer::LightingShader> _lightingShader3D;

        mutable std::shared_ptr<vt::GLTileRenderer> _tileRenderer;
    };

}

#endif