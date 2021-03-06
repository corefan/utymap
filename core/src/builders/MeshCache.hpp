#ifndef BUILDERS_MESHCACHE_HPP_DEFINED
#define BUILDERS_MESHCACHE_HPP_DEFINED

#include "CancellationToken.hpp"
#include "builders/BuilderContext.hpp"

#include <memory>

namespace utymap { namespace builders {

/// Provides the way to cache built meshes to speed up performance.
class MeshCache final
{
public:
    explicit MeshCache(const std::string& directory);

    /// Wraps the context to provide caching behaviour
    BuilderContext wrap(const BuilderContext& context) const;

    /// Fetches data from cache. Returns true if operation is successful
    bool fetch(const BuilderContext& context, const CancellationToken& cancelToken) const;

    /// Releases context.
    void release(const BuilderContext& context, const CancellationToken& cancelToken) const;

    ~MeshCache();

private:
    class MeshCacheImpl;
    std::unique_ptr<MeshCacheImpl> pimpl_;
};

}}

#endif // BUILDERS_MESHCACHE_HPP_DEFINED