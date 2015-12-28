/******************************************************************************
* Copyright (c) 2015, Howard Butler (howard@hobu.co)
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#include <pdal/Metadata.hpp>

#include <libxml/parser.h>
#include <libxml/tree.h>
#include <geos_c.h>
#include <string>
#include <iostream>
#include <stdlib.h>

namespace pdal
{

class PDAL_DLL Ilvis2MetadataReader
{
public:
    MetadataNode * readMetadataFile(std::string filename);

protected:
    void parseGranuleMetaDataFile(xmlNodePtr node, MetadataNode* m);
    void parseGranuleURMetaData(xmlNodePtr node, MetadataNode* m);
    void parseCollectionMetaData(xmlNodePtr node, MetadataNode* m);
    void parseDataFiles(xmlNodePtr node, MetadataNode* m);
    void parseDataFileContainer(xmlNodePtr node, MetadataNode* m);
    void parseECSDataGranule(xmlNodePtr node, MetadataNode* m);
    void parseRangeDateTime(xmlNodePtr node, MetadataNode* m);

    void parsePlatform(xmlNodePtr node, MetadataNode* m);
    void parseInstrument(xmlNodePtr node, MetadataNode* m);
    void parseSensor(xmlNodePtr node, MetadataNode* m);
    void parseSensorCharacteristic(xmlNodePtr node, MetadataNode* m);
    void parseCampaign(xmlNodePtr node, MetadataNode* m);
    void parsePSAs(xmlNodePtr node, MetadataNode* m);
    void parsePSA(xmlNodePtr node, MetadataNode* m);
    void parseXXProduct(std::string type, xmlNodePtr node, MetadataNode* m);

    void parseSpatialDomainContainer(xmlNodePtr node, MetadataNode* m);
    void parseGPolygon(xmlNodePtr node, MetadataNode* m);
    void parseBoundary(xmlNodePtr node, MetadataNode* m);
    void parsePoint(xmlNodePtr node, MetadataNode* m);

private:
    std::string extractString(xmlNodePtr node);
    double extractDouble(xmlNodePtr node);
    int extractInt(xmlNodePtr node);
    long extractLong(xmlNodePtr node);

    xmlNodePtr getNextElementNode(xmlNodePtr node);
    xmlNodePtr getFirstChildElementNode(xmlNodePtr node);
    bool nodeElementIs(xmlNodePtr node, std::string expected);
    void assertElementIs(xmlNodePtr node, std::string expected);
    void assertEndOfElements(xmlNodePtr node);
    int countChildElements(xmlNodePtr node, std::string childName);
    void errWrongElement(xmlNodePtr node, std::string expected);
    void errExpectedEnd(xmlNodePtr node);
};

}