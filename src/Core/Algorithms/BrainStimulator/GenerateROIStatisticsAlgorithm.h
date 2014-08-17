/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2012 Scientific Computing and Imaging Institute,
   University of Utah.

   License for the specific language governing rights and limitations under
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#ifndef ALGORITHMS_MATH_GenerateROIStatisticsAlgorithm_H
#define ALGORITHMS_MATH_GenerateROIStatisticsAlgorithm_H

#include <Core/Algorithms/Base/AlgorithmBase.h>
#include <Core/Algorithms/Math/AlgorithmFwd.h>
#include <Core/Algorithms/BrainStimulator/share.h>
//////////////////////////////////////////////////////////////////////////
/// @todo MORITZ
//////////////////////////////////////////////////////////////////////////
namespace SCIRun {
namespace Core {
namespace Algorithms {
namespace BrainStimulator {
  
  ALGORITHM_PARAMETER_DECL(ROITableValues);
  ALGORITHM_PARAMETER_DECL(StatisticsTableValues);
  ALGORITHM_PARAMETER_DECL(PhysicalUnitStr);
  ALGORITHM_PARAMETER_DECL(CoordinateSpaceLabelStr);

  class SCISHARE GenerateROIStatisticsAlgorithm : public AlgorithmBase
  {
  public:
    AlgorithmOutput run_generic(const AlgorithmInput& input) const;
    GenerateROIStatisticsAlgorithm();
    static const AlgorithmInputName MeshDataOnElements;
    static const AlgorithmInputName PhysicalUnit;
    static const AlgorithmInputName AtlasMesh;
    static const AlgorithmInputName AtlasMeshLabels;
    static const AlgorithmInputName CoordinateSpace;
    static const AlgorithmInputName CoordinateSpaceLabel;
    static const AlgorithmInputName SpecifyROI;
    static const AlgorithmOutputName StatisticalResults;
    static Core::Algorithms::AlgorithmParameterName StatisticsRowName(int i);
  private:
    boost::tuple<Datatypes::DenseMatrixHandle, Variable> run(FieldHandle mesh, FieldHandle AtlasMesh, const FieldHandle CoordinateSpace=FieldHandle(), const std::string& AtlasMeshLabels="", const Datatypes::DenseMatrixHandle specROI=Datatypes::DenseMatrixHandle()) const;
    std::vector<std::string> ConvertInputAtlasStringIntoVector(const  std::string& atlasLabels) const;
    std::set<bool> statistics_based_on_xyz_coodinates(const FieldHandle mesh, const FieldHandle CoordinateSpace, std::set<int>& labelSet, double x, double y, double z, double radius, int material) const;
  };

}}}}

#endif
