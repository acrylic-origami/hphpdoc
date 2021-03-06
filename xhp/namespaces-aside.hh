<?hh // strict
/**
 * Hphpdoc
 *
 * Licensed under the Apache License, Version 2.0 (the "License"); you may not
 * use this file except in compliance with the License. You may obtain a copy of
 * the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations under
 * the License.
 *
 * @copyright 2016 Appertly
 * @license   Apache-2.0
 */

/**
 * Renders an aside of namespaces.
 */
class :hphpdoc:namespaces-aside extends :x:element implements HasXHPHelpers
{
    use XHPHelpers;

    category %flow;
    children empty;
    attribute :aside,
        Traversable<string> namespaces @required;

    protected function render(): XHPRoot
    {
        $namespaces = $this->:namespaces;
        if (count($namespaces) == 0) {
            return <x:frag />;
        }
        return <aside>
            <header>
                <h1>Namespaces</h1>
            </header>
            <hphpdoc:namespaces-list namespaces={$namespaces}/>
        </aside>;
    }
}
