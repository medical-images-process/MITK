/*===================================================================

The Medical Imaging Interaction Toolkit (MITK)

Copyright (c) German Cancer Research Center,
Division of Medical and Biological Informatics.
All rights reserved.

This software is distributed WITHOUT ANY WARRANTY; without
even the implied warranty of MERCHANTABILITY or FITNESS FOR
A PARTICULAR PURPOSE.

See LICENSE.txt or http://www.mitk.org for details.

===================================================================*/

#include "mitkSumOfSquaredDifferencesFitCostFunction.h"
#include "mitkLogMacros.h"

mitk::SumOfSquaredDifferencesFitCostFunction::MeasureType mitk::SumOfSquaredDifferencesFitCostFunction::CalcMeasure(const ParametersType & /*parameters*/, const SignalType &signal) const
{
  MeasureType measure = 0.0;

  for(SignalType::size_type i=0; i<signal.GetSize(); ++i)
  {
    measure += (m_Sample[i] - signal[i]) *  (m_Sample[i] - signal[i]);
  }

  return measure;
}
