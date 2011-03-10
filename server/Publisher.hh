/*
 * Copyright 2011 Nate Koenig & Andrew Howard
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
/* Desc: Handles pushing messages out on a named topic
 * Author: Nate Koenig
 */

#ifndef PUBLISHER_HH
#define PUBLISHER_HH

#include <google/protobuf/message.h>
#include <boost/shared_ptr.hpp>

namespace gazebo
{
  /// \brief A publisher of messages on a topic
  class Publisher
  {
    /// \brief Default Constructor
    public: Publisher() {}

    /// \brief Use this constructor
    /// \param topic Name of topic
    /// \param msg_type Type of the message which is to be published
    public: Publisher(const std::string &topic, const std::string &msg_type);

    /// \brief Destructor
    public: virtual ~Publisher();

    /// \brief Publish a message on the topic
    public: void Publish( google::protobuf::Message &message );

    private: std::string topic;
    private: std::string msg_type;
  };
  typedef boost::shared_ptr<Publisher> PublisherPtr;
}

#endif
