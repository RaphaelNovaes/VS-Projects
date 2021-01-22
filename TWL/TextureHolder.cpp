#include "TextureHolder.h"
// Include the "assert feature"
#include <assert.h>
TextureHolder *TextureHolder::m_s_Instance = nullptr;
TextureHolder::TextureHolder()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}
Texture& TextureHolder::GetTexture(string const &filename)
{
	// Get a reference to m_Textures using m_s_Instance
	auto &m = m_s_Instance->m_Textures;
	// Auto is the equivalent of map<string, Texture>
	// Create an interator to hold a key-value-pair (kvp) and search for the required kvp using the passed in the file name
	auto keyValuePair = m.find(filename);
	// Auto is the equivalent of map<string, Texture>::iterator

	// Did we find a match ?
	if (keyValuePair != m.end())
	{
		// Yes, return the texture, the second part of the kvp, the texture
		return keyValuePair->second;
	}
	else
	{
		// File name not found, create a new key value pair using the file name
		auto &texture = m[filename];
		// Load the texture from file in the usual way
		texture.loadFromFile(filename);
		// Return the texture to the calling code
		return texture;
	}
}